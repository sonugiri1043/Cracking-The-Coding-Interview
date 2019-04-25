## Personal Financial Manager
Explain how you would design a personal financial manager (like Mint.com). This system
would connect to your bank accounts, analyze your spending habits, and make recommendations.

## Solution
The first thing we need to do is define what it is exactly that we are building.

### Scope the Problem
Ordinarily, you would clarify this system with your interviewer. We'll scope the problem as follows:

- You create an account and add your bank accounts. You can add multiple bank accounts. You can also
add them at a later point in time.
- It pulls in all your financial history, or as much of it as your bank will allow.
- This financial history includes outgoing money (things you bought or paid for), incoming money (salary
  and other payments), and your current money (what's in your bank account and investments).
- Each payment transaction has a "category" associated with it (food, travel, clothing, etc.).
- There is some sort of data source provided that tells the system, with some reliability, which category a
  transaction is associated with. The user might, in some cases, override the category when it's improperly
  assigned (e.g., eating at the cafe of a department store getting assigned to "clothing" rather than "food").
- Users will use the system to get recommendations on their spending. These recommendations will
  come from a mix of "typical" users ("people generally shouldn't spend more than X% of their income
  on clothing"), but can be overridden with custom budgets. This will not be a primary focus right now.
- We assume this is just a website for now, although we could potentially talk about a mobile app as well.
- We probably want email notifications either on a regular basis, or on certain conditions (spending over
  a certain threshold, hitting a budget max, etc.).
- We'll assume that there's no concept of user-specified rules for assigning categories to transactions.

This gives us a basic goal for what we want to build.

### Make Reasonable Assumptions
Now that we have the basic goal for the system, we should define some further assumptions about the
characteristics of the system.
- Adding or removing bank accounts is relatively unusual.
- The system is write-heavy. A typical user may make several new transactions daily, although few users
  would access the website more than once a week. In fact, for many users, their primary interaction might
  be through email alerts.
- Once a transaction is assigned to a category, it will only be changed if the user asks to change it. The
  system will never reassign a transaction to a different category "behind the scenes'; even if the rules
  change. This means that two otherwise identical transactions could be assigned to different categories
  if the rules changed in between each transaction's date. We do this because it may confuse users if their
  spending per category changes with no action on their part.
- The banks probably won't push data to our system. Instead, we will need to pull data from the banks.
- Alerts on users exceeding budgets probably do not need to be sent instantaneously. (That wouldn't be
  realistic anyway, since we won't get the transaction data instantaneously.) It's probably pretty safe for
  them to be up to 24 hours delayed.
It's okay to make different assumptions here, but you should explicitly state them to your interviewer.

### Step 3: Draw the Major Components
The most naive system would be one that pulls bank data on each login, categorizes all the data, and then
analyzes the user's budget. This wouldn't quite fit the requirements, though, as we want email notifications
on particular events.

We can do a bit better.
```bash
        bank data Synchronizer
	        |
	        |
	        ↓
	Raw transaction data ------> Categorizer
                                       |
                                       |
                                       ↓
        Frontend <-------------->Categorized Transaction
           ^                            |
           |                            |
	   ↓                            ↓
        budget data <------------ budget analyzer

```
With this basic architecture, the bank data is pulled at periodic times (hourly or daily). The frequency may
depend on the behavior of the users. Less active users may have their accounts checked less frequently.

Once new data arrives, it is stored in some list of raw, unprocessed transactions. This data is then pushed to
the categorizer, which assigns each transaction to a category and stores these categorized transactions in
another datastore.

The budget analyzer pulls in the categorized transactions, updates each user's budget per category, and
stores the user's budget.

The frontend pulls data from both the categorized transactions datastore as well as from the budget datastore.
Additionally, a user could also interact with the frontend by changing the budget or the categorization
of their transactions.

### Step4: Identify the key issues
This will be a very data-heavy system. We want it to feel snappy and responsive, though, so we'll want as
much processing as possible to be asynchronous.

We will almost certainly want at least one task queue, where we can queue up work that needs to be done.
This work will include tasks such as pulling in new bank data, re-analyzing budgets, and categorizing new
bank data. It would also include re-trying tasks that failed.

These tasks will likely have some sort of priority associated with them, as some need to be performed more
often than others. We want to build a task queue system that can prioritize some task types over others,
while still ensuring that all tasks will be performed eventually. That is, we wouldn't want a low priority task
to essentially "starve" because there are always higher priority tasks.

One important part of the system that we haven't yet addressed will be the email system. We could use a
task to regularly crawl user's data to check if they're exceeding their budget, but that means checking every
single user daily. Instead, we'll want to queue a task whenever a transaction occurs that potentially exceeds
a budget. We can store the current budget totals by category to make it easy to understand if a new transaction
exceeds the budget.

We should also consider incorporating the knowledge (or assumption) that a system like this will probably
have a large number of inactive users-users who signed up once and then haven't touched the system
since. We may want to either remove them from the system entirely or deprioritize their accounts. We'll
want some system to track their account activity and associate priority with their accounts.

The biggest bottleneck in our system will likely be the massive amount of data that needs to be pulled
and analyzed. We should be able to fetch the bank data asynchronously and run these tasks across many
servers. We should drill a bit deeper into how the categorizer and budget analyzer work.

**Categorizer and Budget Analyzer**
One thing to note is that transactions are not dependent on each other. As soon as we get a transaction for
a user, we can categorize it and integrate this data. It might be inefficient to do so, but it won't cause any
inaccuracies.

Should we use a standard database for this? With lots of transactions coming in at once, that might not be
very efficient. We certainly don't want to do a bunch of joins.

It may be better instead to just store the transactions to a set of flat text files. We assumed earlier that the
categorizations are based on the seller's name alone. If we're assuming a lot of users, then there will be a lot
of duplicates across the sellers. If we group the transaction files by seller's name, we can take advantage of
these duplicates.

The categorizer can do something like this:
```bash
    Raw transaction data,----------> categorized data, ---------> update categorized
    grouped by seller                grouped by user              transactions
                                          |
                                          |
					  ↓
                                     merge & group by
                                     user and category
                                          |
                                          |
                                          ↓
                                      update budget
```
It first gets the raw transaction data, grouped by seller. It picks the appropriate category for the seller (which
might be stored in a cache for the most common sellers), and then applies that category to all those transactions.

After applying the category, it re-groups all the transactions by user. Then, those transactions are inserted
into the datastore for this user.

```bash
before categorizer
--------------------
amazon/
	user121,$5.43,Aug 13
	user922,$15.39,Aug 27
	...
comcast/
	user922,$9.29,Aug 24
	user248,$40.13,Aug 18
	 ...

after categorizer
--------------------
user121/
	amazon,shopping,$5.43,Aug 13
	...
user922/
	amazon,shopping,$15.39,Aug 27
	comcast,utilities,$9.29,Aug 24
	...
user248/
	comcast,utilities,$40.13,Aug 18
	...
```
Then, the budget analyzer comes in. It takes the data grouped by user, merges it across categories (so all
Shopping tasks for this user in this timespan are merged). and then updates the budget.

Most of these tasks will be handled in simple log files. Only the final data (the categorized transactions and
the budget analysis) will be stored in a database. This minimizes writing and reading from the database.
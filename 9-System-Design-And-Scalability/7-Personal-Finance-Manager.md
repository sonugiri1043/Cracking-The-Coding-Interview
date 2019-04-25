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

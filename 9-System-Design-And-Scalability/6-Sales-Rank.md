## Sales Rank:
A large eCommerce company wishes to list the best-selling products, overall and by category.
For example, one product might be the 1056th best-selling product overall but the 13th
best-selling product under "Sports Equipment" and the 24th best-selling product under "Safety."
Describe how you would design this system.

### Step 1: Scope the Problem
We need to define what exactly we're building.
- We'll assume that we're only being asked to design the components relevant to this question,
  and not the entire eCommerce system. In this case, we might touch the design of the frontend
  and purchase components, but only as it impacts the sales rank.
- We should also define what the sales rank means. Is it total sales over all time? Sales in the
  last month? Last week? Or some more complicated function (such as one involving some sort of
  exponential decay of sales data)? This would be something to discuss with your interviewer. We
  will assume that it is simply the total sales over the past week.
- We will assume that each product can be in multiple categories, and that there is no concept of
   "subcategories'.

### Step 2: Make Reasonable Assumptions
These are the sorts of things you'd want to discuss with your interviewer.
- We will assume that the stats do not need to be 100% up-to-date. Data can be up to an hour old
  for the most popular items (for example, top 100 in each category), and up to one day old for the
  less popular items. That is, few people would care if the 2,809,132th best-selling item should
  have actually been listed as 2,789,158th instead.
- Precision is important for the most popular items, but a small degree of error is okay for the less
  popular items. We will assume that the data should be updated every hour (for the most popular items),
  but the time range for this data does not need to be precisely the last seven days (168 hours).
  If it's sometimes more like 150 hours, that's okay.
- We will assume that the categorizations are based strictly on the origin of the transaction ( i.e.,
  the seller's name ), not the price or date.

The important thing is not so much which decision you made at each possible issue, but whether it occurred
to you that these are assumptions. We should get out as many of these assumptions as possible in the
beginning. It's possible you will need to make other assumptions along the way.

### Step 3: Draw the Major Components
We should now design just a basic, naive system that describes the major components. This is where you
would go up to a whiteboard.					
>        
 Front End <----- sales rank data <-------Database<---(Orders added to DB)---Purchase System 

In this simple design, we store every order as soon as it comes into the database. Every hour or so,
we pull sales data from the database by category, compute the total sales, sort it, and store it in
some sort of sales rank data cache (which is probably held in memory). The frontend just pulls the
sales rank from this table, rather than hitting the standard database and doing its own analytics.

### Step 4: Identify the Key Issues
**Analytics are Expensive**

In the naive system, we periodically query the database for the number of sales in the past week for
each product. This will be fairly expensive. That's running a query over all sales for all time.

Our database just needs to track the total sales. We'll assume (as noted in the beginning of the solution)
that the general storage for purchase history is taken care of in other parts of the system, and we just need
to focus on the sales data analytics.

Instead of listing every purchase in our database, we'll store just the total sales from the last week. Each
purchase will just update the total weekly sales.

Tracking the total sales takes a bit of thought. If we just use a single column to track the total sales
over the past week, then we'll need to re-compute the total sales every day (since the specific days covered
in the last seven days change with each day). That is unnecessarily expensive.

Instead, we'll just use a table like this.

| Product ID | Total | Sun | Mon | Tues | Wed | Thurs | Fri | Sat |

This is essentially like a circular array. Each day, we clear out the corresponding day of the week. On each
purchase, we update the total sales count for that product on that day of the week, as well as the total
count.

We will also need a separate table to store the associations of product IDs and categories.

| Prod ID | Category ID |

To get the sales rank per category, we'll need to join these tables.

**Database Writes are Very Frequent** 

Even with this change, we'll still be hitting the database very frequently. With the amount of purchases that
could come in every second, we'll probably want to batch up the database writes.

Instead of immediately committing each purchase to the database, we could store purchases in some sort
of in-memory cache (as well as to a log file as a backup). Periodically, we'll process the log / cache data,
gather the totals, and update the database.

> We should quickly think about whether or not it's feasible to hold this in memory. If there are 10
million products in the system, can we store each (along with a count) in a hash table? Yes. If each
product 10 is four bytes (which is big enough to hold up to 4 billion unique IDs) and each count
is four bytes (more than enough), then such a hash table would only take about 40 megabytes.
Even with some additional overhead and substantial system growth, we would still be able to fit
this all in memory.

After updating the database, we can re-run the sales rank data. We need to be a bit careful here, though.
If we process one product's logs before another's, and re-run thestats in between, we could create a bias
in the data (since we're including a larger timespan for one product than its "competing" product).

We can resolve this by either ensuring that the sales rank doesn't run until all the stored data is processed
(difficult to do when more and more purchases are coming in), or by dividing up the in-memory cache by
some time period. **If we update the database for all the stored data up to a particular moment in time, this
ensures that the database will not have biases.**

**Joins are Expensive**
We have potentially tens of thousands of product categories. For each category, we'll need to first pull the
data for its items (possibly through an expensive join) and then sort those.

Alternatively, we could just do one join of products and categories, such that each product will be listed
once per category. Then, if we sorted that on category and then product 10, we could just walk the results
to get the sales rank for each category.

Rather than running thousands of queries (one for each category), we could sort the data on the category
first and then the sales volume. Then, if we walked those results, we would get the sales rank for each
category. We would also need to do one sort of the entire table on just sales number, to get the overall rank.
We could also just keep the data in a table like this from the beginning, rather than doing joins. This would
require us to update multiple rows for each product.

**Database Queries Might Still Be Expensive**

Alternatively, if the queries and writes get very expensive, we could consider forgoing a database entirely
and just using log files. This would allow us to take advantage of something like MapReduce.
Under this system, we would write a purchase to a simple text file with the product ID and time stamp. Each
category has its own directory, and each purchase gets written to all the categories associated with that
product.

We would run frequent jobs to merge files together by product 10 and t ime ranges, so that eventually all
purchases in a given day (or possibly hour) were grouped together.

To get the best-selling products within each category, we just need to sort each directory.
How do we get the overall ranking? There are two good approaches:
- We could treat the general category as just another directory, and write every purchase to that directory.
That would mean a lot of files in this directory.
- Or, since we'll already have the products sorted by sales volume order for each category, we can also do
an N-way merge to get the overall rank.

Alternatively, we can take advantage of the fact that the data doesn't need (as we assumed earlier) to be
100% up-to-date. We just need the most popular items to be up-to-date.

We can merge the most popular items from each category in a pairwise fashion. So, two categories get
paired together and we merge the most popular items (the first 100 or so). After we have 100 items in this
sorted order, we stop merging this pair and move onto the next pair.

To get the ranking for all products, we can be much lazier and only run this work once a day.
One of the advantages of this is that it scales nicely. We can easily divide up the files across multiple servers,
as they aren't dependent on each other.
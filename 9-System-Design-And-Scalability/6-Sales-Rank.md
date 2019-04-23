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
some sort of sales rank data cache (which is probably held in memory). The frontend just pulls the sales
rank from this table, rather than hitting the standard database and doing its own analytics.

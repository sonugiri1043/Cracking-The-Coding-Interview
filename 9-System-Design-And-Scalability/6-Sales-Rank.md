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



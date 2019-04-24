## Design a system like Pastebin, where a user can enter a piece of text and get a randomly
generated URL for public access.

## Solution
We can start with clarifying the specifics of this system.

### Step 1: Scope the Problem
- The system does not support user accounts or editing documents.
- The system tracks analytics of how many times each page is accessed.
- Old documents get deleted after not being accessed for a sufficiently long period oftime.
- While there isn't true authentication on accessing documents, users should not be able to "guess"
  document URLs easily.
- The system has a frontend as well as an API.
- The analytics for each URL can be accessed through a "stats" link on each page. It is not shown by
  default, though.

### Step 2: Make Reasonable Assumptions
- The system gets heavy traffic and contains many millions of documents.
- Traffic is not equally distributed across documents. Some documents get much more access than
  others.
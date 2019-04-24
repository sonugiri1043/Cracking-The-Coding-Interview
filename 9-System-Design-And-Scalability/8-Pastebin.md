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

### Step 3: Draw the Major Components
We can sketch out a simple design. We'll need to keep track of URLs and the files associated with them, as
well as analytics for how often the files have been accessed.

How should we store the documents? We have two options: we can store them in a database or we can
store them on a file. Since the documents can be large and it's unlikely we need searching capabilities,
storing them on a file is probably the better choice.

A simple design like this might work well:
```bash
                  |--------- Server with files
                  |
 URL to file DB --|--------- Server with files
                  |
                  |--------- Server with files
```

Here, we have a simple database that looks up the location (server and path) of each file. When we have a
request for a URL, we look up the location of the URL within the datastore and then access the file.

Additionally, we will need a database that tracks analytics. We can do this with a simple data store that adds
each visit (including timestamp, IP address, and location) as a row in a database. When we need to access
the stats of each visit, we pull the relevant data in from this database.

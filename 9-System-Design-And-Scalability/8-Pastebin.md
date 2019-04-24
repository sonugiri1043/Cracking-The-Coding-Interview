## Pastebin
Design a system like Pastebin, where a user can enter a piece of text and get a randomly
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

### Step 4: Identify the Key Issues
The first issue that comes to mind is that some documents will be accessed much more frequently than
others. Reading data from the filesystem is relatively slow compared with reading from data in memory.
Therefore, we probably want to use a cache to store the most recently accessed documents. This will ensure
that items accessed very frequently (or very recently) will be quickly accessible. Since documents cannot be
edited, we will not need to worry about invalidating this cache.

We should also potentially consider sharding the database. We can shard it using some mapping from the
URL (for example, the URL's hash code modulo some integer), which will allow us to quickly locate the database
which contains this file.

In fact, we could even take this a step further. We could skip the database entirely and just let a hash of the
URL indicate which server contains the document. The URL itself could reflect the location of the document.
One potential issue from this is that if we need to add servers, it could be difficult to redistribute the documents.

**Generating URLs**

We want URLs to be difficult to access without being provided the link.
One simple path is to generate a random GUID (e.g., SdSOe8ac-S7cb-4aOd-8661-bcdee2S48979). This is a
128-bit value that, while not strictly guaranteed to be unique, has low enough odds of a collision that we
can treat it as unique. The drawback of this plan is that such a URL is not very "pretty" to the user. We could
hash it to a smaller value, but then that increases the odds of collision.

We could do something very similar, though. We could just generate a 10-character sequence of letters
and numbers, which gives us 36^10 possible strings. Even with a billion URLs, the odds of a collision on any
specific URL are very low.
>This is not to say that the odds of a collision over the whole system are low. They are not. Anyone
specific URL is unlikely to collide. However, after storing a billion URLs, we are very likely to have
a collision at some point.

Assuming that we aren't okay with periodic (even if unusual) data loss, we'll need to handle these collisions.
We can either check the datastore to see if the URL exists yet or, if the URL maps to a specific server, just
detect whether a file already exists at the destination.

When a collision occurs, we can just generate a new URL. With 3610 possible URLs, collisions would be rare
enough that the lazy approach here (detect collisions and retry) is sufficient.

**Analytics**
The final component to discuss is the analytics piece. We probably want to display the number of visits, and
possibly break this down by location or time.

We have two options here:
- Store the raw data from each visit.
- Store just the data we know we'll use (number of visits, etc.).

It probably makes sense to store the raw data. We never know what features we'll add to the analytics down the road.
The raw data allows us flexibility.

This does not mean that the raw data needs to be easily searchable or even accessible. We can just store a
log of each visit in a file, and back this up to other servers.

One issue here is that this amount of data could be substantial. We could potentially reduce the space usage
considerably by storing data only probabilistically. Each URL would have a storage_probability associated
with it. As the popularity of a site goes up, the storage_probability goes down. For example,
a popular document might have data logged only one out of every ten times, at random. When we look
up the number of visits for the site, we'll need to adjust the value based on the probability (for example, by
multiplying it by 10). This will of course lead to a small inaccuracy, but that may be acceptable.

The log files are not designed to be used frequently. We will want to also store this precomputed data in a
datastore. If the analytics just displays the number of visits plus a graph over time, this could be kept in a
separate database.

```bash
URL       | Month and Year | Visits
12ab31b92p  December 2013    242119
12ab31b92p  January 2014     429918
```

Every time a URL is visited, we can increment the appropriate row and column. This datastore can also be
sharded by the URL.

As the stats are not listed on the regular pages and would generally be of less interest, it should not face as
heavy of a load. We could still cache the generated HTML on the frontend servers, so that we don't continuously
reaccess the data for the most popular URLs.

Follow-Up Questions
- How would you support user accounts?
- How would you add a new piece of analytics (e.g., referral source) to the stats page?
- How would your design change if the stats were shown with each document?
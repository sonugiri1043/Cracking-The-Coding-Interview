## Cache
**Imagine a web server for a simplified search engine. This system has 100 machines to
respond to search queries, which may then call out using processSearch ( string query )
to another cluster of machines to actually get the result. The machine which responds to
a given query is chosen at random, so you cannot guaranteethat the same machine will always respond to
the same request. The method processSearch is very expensive. Design a caching mechanism
to cache the results of the most recent queries. Be sure to explain how you would update the cache
when data changes.**

## Solution
We will make reasonable assumptions for the purposes of this solution.

### Assumptions
- Other than calling out to processSearch as necessary, all query processing happens on the initial
machine that was called.
- The number of queries we wish to cache is large (millions). Calling between machines is relatively quick.
- The result for a given query is an ordered list of URLs, each of which has an associated 50 character title
and 200 character summary.
- The most popular queries are extremely popular, such that they would always appear in the cache.

### System Requirements
When designing the cache, we know we'll need to support two primary functions:
- Efficient lookups given a key.
- Expiration of old data so that it can be replaced with new data.
In addition, we must also handle updating or clearing the cache when the results for a query change.
Because some queries are very common and may permanently reside in the cache, we cannot just wait for
the cache to naturally expire.

### Step 1: Design a Cache for a Single System
A good way to approach this problem is to start by designing it for a single machine. So, how would you
create a data structure that enables you to easily purge old data and also efficiently look up a value based
on a key?
- A linked list would allow easy purging of old data, by moving "fresh" items to the front. We could implement
it to remove the last element of the linked list when the list exceeds a certain size.
- A hash table allows efficient lookups of data, but it wouldn't ordinarily allow easy data purging.

How can we get the best of both worlds? By merging the two data structures. Here's how this works:
Just as before, we create a linked list where a node is moved to the front every time it's accessed. This way,
the end of the linked list will always contain the stalest information.

In addition, we have a hash table that maps from a query to the corresponding node in the linked list. This
allows us to not only efficiently return the cached results, but also to move the appropriate node to the
front of the list, thereby updating its "freshness".

### Step 2: Expand to Many Machines
Now that we understand how to design this for a single machine, we need to understand how we would
design this when queries could be sent to many different machines. Recall from the problem statement that
there's no guarantee that a particular query will be consistently sent to the same machine.
The first thing we need to decide is to what extent the cache is shared across machines. We have several
options to consider.

#### Option 1: Each machine has its own cache.
A simple option is to give each machine its own cache. This means that if "foo" is sent to machine 1 twice in
a short amount of time, the result would be recalled from the cache on the second time. But, if"foo" is sent
first to machine 1 and then to machine 2, it would be treated as a totally fresh query both times.
This has the advantage of being relatively quick, since no machine-to-machine calls are used. The cache,
unfortunately, is somewhat less effective as an optimization tool as many repeat queries would be treated
as fresh queries.

#### Option 2: Each machine has a copy of the cache.
On the other extreme, we could give each machine a complete copy of the cache. When new items are
added to the cache, they are sent to all machines. The entire data structure-linked list and hash table would
be duplicated.
This design means that common queries would nearly always be in the cache, as the cache is the same
everywhere. The major drawback however is that updating the cache means firing off data to N different
machines, where N is the size of the response cluster. Additionally, because each item effectively takes up N
times as much space, our cache would hold much less data.

#### Option 3: Each machine stores a segment of the cache.
A third option is to divide up the cache, such that each machine holds a different part of it. Then, when
machine i needs to look up the results for a query, machine i would figure out which machine holds this
value, and then ask this other machine (machine j) to look up the query in j's cache.

But how would machine i know which machine holds this part of the hash table?

One option is to assign queries based on the formula hash(query)%N. Then, machine i only needs to
apply this formula to know that machine j should store the results for this query.

So, when a new query comes in to machine i, this machine would apply the formula and call out to machine
j. Machine j would then return the value from its cache or call processSearch(query) to get the
results. Machine j would update its cache and return the results back to i.

Alternatively, you could design the system such that machine j just returns null if it doesn't have the
query in its current cache. This would require machine i to call processSearch and then forward
the results to machine j for storage. This implementation actually increases the number of machine-to machine
calls, with few advantages.

#### Step 3: Updating results when contents change
Recall that some queries may be so popular that, with a sufficiently large cache, they would permanently
be cached. We need some sort of mechanism to allow cached results to be refreshed, either periodically or
"on-demand" when certain content changes.

To answer this question, we need to consider when results would change. The primary times would be when:
1. The content at a URL changes (or the page at that URL is removed).
2. The ordering of results change in response to the rank of a page changing.
3. New pages appear related to a particular query.

To handle situations #1 and #2, we could create a separate hash table that would tell us which cached
queries are tied to a specific URL. This could be handled completely separately from the other caches, and
reside on different machines. However, this solution may require a lot of data.

Alternatively, if the data doesn't require instant refreshing (which it probably doesn't), we could periodically
crawl through the cache stored on each machine to purge queries tied to the updated URLs.
Situation #3 is substantially more difficult to handle. We could update single word queries by parsing the
content at the new URL and purging these one-word queries from the caches. But, this will only handle the
one-word queries.

A good way to handle Situation #3 (and likely something we'd want to do anyway) is to implement an "automatic
time-out" on the cache. That is, we'd impose a time out where no query, rega rdless of how popular it
is, can sit in the cache for more than x minutes. This will ensure that all data is periodically refreshed.

#### Step 4: Further Enhancements
There are a number of improvements and tweaks you could make to this design depending on the assumptions
you make and the situations you optimize for.

One such optimization is to better support the situation where some queries are very popular. For example,
suppose (as an extreme example) a particular string constitutes 1 % of all queries. Rather than machine i
forwarding the request to machine j every time, machine i could forward the request just once to j , and
then i could store the results in its own cache as well.

Alternatively, there may also be some possibility of doing some sort of re-architecture of the system to
assign queries to machines based on their hash value (and therefore the location of the cache), rather than
randomly. However, this decision may come with its own set of trade-offs.

Another optimization we could make is to the "automatic time out" mechanism. As initially described, this
mechanism purges any data after X minutes. However, we may want to update some data (like current
news) much more frequently than other data (like historical stock prices). We could implement timeouts
based on topic or based on URLs. In the latter situation, each URL would have a time out value based on
how frequently the page has been updated in the past. The time out for the query would be the minimum
of the time outs for each URL.
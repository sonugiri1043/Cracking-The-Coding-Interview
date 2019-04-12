## Key Concepts

### Horizontal vs. Vertical Scaling
A system can be scaled one of two ways.
- Vertical scaling means increasing the resources of a specific node. For example,
  you might add additional memory to a server to improve its ability to handle load changes.
- Horizontal scaling means increasing the number of nodes. For example, you might add additional
  servers, thus decreasing the load on anyone server.

Vertical scaling is generally easier than horizontal scaling, but it's limited. You can only add
so much memory or disk space.

### load Balancer
Typically, some frontend parts of a scalable website will be thrown behind a load balancer. This
allows a system to distribute the load evenly so that one server doesn't crash and take down the
whole system. To do so, of course, you have to build out a network of cloned servers that all have
essentially the same code and access to the same data.

### Database Denormalization and NoSQL
Joins in a relational database such as SQL can get very slow as the system grows bigger. For this
reason, you would generally avoid them.
Denormalization is one part of this. Denormalization means adding redundant information into a
database to speed up reads. For example, imagine a database describing projects and tasks ( where a
project can have multiple tasks ). You might need to get the project name and the task information.
Rather than doing a join across these tables, you can store the project name within the task table
(in addition to the project table).
Or, you can go with a NoSQl database. A NoSQl database does not support joins and might structure data
in a different way. It is designed to scale better.

### Database Partitioning (Sharding)
Sharding means splitting the data across multiple machines while ensuring you have a way of figuring
out which data is on which machine.
A few common ways of partitioning include:
- **Vertical Partitioning:** This is basically partitioning by feature. For example, if you were building
a social network, you might have one partition for tables relating to profiles, another one for messages,
and so on. One drawback of this is that if one of these tables gets very large, you might need to repartition
that database ( possibly using a different partitioning scheme ).
- **Key-Based (or Hash-Based) Partitioning:** This uses some part of the data (for example an ID) to
partition it. A very simple way to do this is to allocate N servers and put the data on mod (key % N).
One issue with this is that the number of servers you have is effectively fixed. Adding additional
servers means reallocating all the data - a very expensive task.
- **Directory-Based Partitioning:** In this scheme, you maintain a lookup table for where the data can be
found. This makes it relatively easy to add additional servers, but it comes with two major drawbacks.
First, the lookup table can be a single point of failure. Second, constantly accessing this table impacts
performance.
Many architectures actually end up using multiple partitioning schemes.

### Caching
An in-memory cache can deliver very rapid results. It is a simple key-value pairing and typically sits between
your application layer and your data store.
When an application requests a piece of information, it first tries the cache. If the cache does not contain the
key, it will then look up the data in the data store. ( At this point, the data might-or might not-be stored
in the data store. )
When you cache, you might cache a query and its results directly. Or, alternatively, you can cache the specific
object (for example, a rendered version of a part of the website, or a list of the most recent blog posts).

### Asynchronous Processing & Queues
Slow operations should ideally be done asynchronously. Otherwise, a user might get stuck waiting and
waiting for a process to complete.

### Networking Metrics
Some ofthe most important metrics around networking include:
- **Bandwidth:** This is the maximum amount of data that can be transferred in a unit of time. It is typically
expressed in bits per second (or some similar ways, such as gigabytes per second).
- **Throughput:** Whereas bandwidth is the maximum data that can be transferred in a unit of time,
throughput is the actual amount of data that is transferred.
- **Latency:** This is how long it takes data to go from one end to the other. That is, it is the delay between the
sender sending information (even a very small chunk of data) and the receiver receiving it.

### MapReduce
MapReduce is often associated with Google, but it's used much more broadly than that. A MapReduce
program is typically used to process large amounts of data.

As its name suggests, a MapReduce program requires you to write a Map step and a Reduce step. The rest
is handled by the system.
- Map takes in some data and emits a <key, value> pair.
- Reduce takes a key and a set of associated values and "reduces" them in some way, emitting a new key
and value. The results of this might be fed back into the Reduce program for more reducing.

MapReduce allows us to do a lot of processing in parallel, which makes processing huge amounts of data
more scalable.

### Considerations
In addition to the earlier concepts to learn, you should consider the following issues when designing a
system.
**Failures:** Essentially any part of a system can fail. You'll need to plan for many or all of these failures.
**Availability and Reliability:** Availability is a function of the percentage of time the system is operational.
   Reliability is a function of the probability that the system is operational for a certain unit of time.
**Read-heavy vs. Write-heavy:** Whether an application will do a lot of reads or a lot of writes impacts the
   design. If it's write-heavy, you could consider queuing up the writes (but think about potential failure
   here!). If it's read-heavy, you might want to cache. Other design decisions could change as well.
**Security:** Security threats can, of course, be devastating for a system. Think about the types of issues a
   system might face and design around those.

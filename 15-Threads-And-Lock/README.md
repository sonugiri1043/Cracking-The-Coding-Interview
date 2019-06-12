## Deadlocks and Deadlock Prevention
A deadlock is a situation where a thread is waiting for an object lock that another thread holds, and this
second thread is waiting for an object lock that the first thread holds (or an equivalent situation with several
threads). Since each thread is waiting for the other thread to relinquish a lock, they both remain waiting
forever. The threads are said to be deadlocked.
In order for a deadlock to occur, you must have all four of the following conditions met:
- 1. Mutual Exclusion: Only one process can access a resource at a given time. (Or, more accurately, there is
limited access to a resource. A deadlock could also occur if a resource has limited quantity.)
- 2. Hold and Wait: Processes already holding a resource can request additional resources, without relinquishing
their current resources.
- 3. No Preemption: One process cannot forcibly remove another process' resource.
- 4. Circular Wait: Two or more processes form a circular chain where each process is waiting on another
resource in the chain.

Deadlock prevention entails removing any of the above conditions, but it gets tricky because many of these
conditions are difficult to satisfy. For instance, removing #1 is difficult because many resources can only
be used by one process at a time (e.g., printers). Most deadlock prevention algorithms focus on avoiding
condition #4: circular wait.
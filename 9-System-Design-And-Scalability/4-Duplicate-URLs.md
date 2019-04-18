## Duplicate URLs:
**You have 10 billion URLs. How do you detect the duplicate documents? In this case,
assume "duplicate" means that the URLs are identical.**

## Solution
**How much space do 10 billion URLs take up?**
If each URL is an average of 100 characters, and each character is 4 bytes, then this list of 10 billion URLs
will take up about 4 terabytes. We are probably not going to hold that much data in memory.
2^30 = 1 Billion -> 10 billion * 100 char per URL * 4 byte per character.

Let's just pretend for a moment that we were miraculously holding this data in memory, since it's useful
to first construct a solution for the simple version. Under this version of the problem, we would just create
a hash table where each URL maps to true if it's already been found elsewhere in the list. As an alternative
solution, we could sort the list and look for the duplicate values that way. That will take a bunch of extra
time and offers few advantages.

What happens when we have all 4000 gigabytes of data and we can't store it all in memory? We could solve this
either by storing some of the data on disk or by splitting up the data across machines.

### Solution 1: Disk Storage
If we stored all the data on one machine, we would do two passes of the document. The first pass would
split the list of URLs into 4000 chunks of 1 GB each. An easy way to do that might be to store each URL in
a file named <x>.txt where x = hash(url)%4000. That is, we divide up the URLs based on their hash
value (modulo the number of chunks). This way, all URLs with the same hash value would be in the same file.
In the second pass, we would essentially implement the simple solution we came up with earlier: load each
file into memory, create a hash table of the URLs, and look for duplicates.

### Solution 2: Multiple Machines
The other solution is to perform essentially the same procedure, but to use multiple machines. In this solution,
rather than storing the data in file <x>. txt, we would send the URL to machine x.
Using multiple machines has pros and cons. The main pro is that we can **parallelize the operation**, such
that all 4000 chunks are processed simultaneously. For large amounts of data, this might result in a faster
solution.
The disadvantage though is that we are now relying on 4000 different machines to operate perfectly. That
may not be realistic ( particularly with more data and more machines ), and we'll need to start considering
how to handle failure. Additionally, we have increased the complexity of the system simply by involving so
many machines.
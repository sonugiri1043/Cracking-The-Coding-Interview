## Problem
Given a list of millions of documents, how would you find all documents that contain a list of words?
The words can appear in any order, but they must be complete words. That is, "book" does not match "bookkeeper."

Before we start solving the problem, we need to understand whether this is a one time only operation, or if
this findWords procedure will be called repeatedly. Let's assume that we will be calling findWords many
times for the same set of documents, and, therefore, we can accept the burden of pre-processing.

### Step 1
The first step is to pretend we just have a few dozen documents. How would we implement findWords in
this case ?
One way to do this is to pre-process each document and create a hash table index. This hash table would
**map from a word to a list of the documents that contain that word**.
- "books" -> { doc2, doc3, doc6, doc8 }
- "many" -> { docl, doc3, doc7, doc8, doc9 }

To search for "many books" we would simply do an intersection on the values for "books" and "many' and
return { doc3, doc8 } as the result.

### Step 2
We probably need to divide up the documents across many machines. Also, depending on a variety of factors,
such as the number of possible words and the repetition of words in a document, we may not be
able to fit the full hash table on one machine. Let's assume that this is the case.

This division introduces the following key concerns:
- How will we divide up our hash table? We could divide it up by keyword, such that a given machine
contains the full document list for a given word. Or, we could divide by document, such that a machine
contains the keyword mapping for only a subset of the documents.
- Once we decide how to divide up the data, we may need to process a document on one machine and
push the results off to other machines. What does this process look like? (Note: if we divide the hash
table by document, this step may not be necessary.)
- We will need a way of knowing which machine holds a piece of data. What does this lookup table look
like, and where is it stored ?

### Step 3
In Step 3, we find solutions to each of these issues. One solution is to divide up the words alphabetically
by keyword, such that each machine controls a range of words (e.g., "after" through "apple").
We can implement a simple algorithm in which we iterate through the keywords alphabetically, storing as
much data as possible on one machine. When that machine is full, we can move to the next machine.
The advantage of this approach is that the lookup table is small and simple (since it must only specify a
range of values), and each machine can store a copy of the lookup table. However, the disadvantage is that
if new documents or words are added, we may need to perform an expensive shift of keywords.

To find all the documents that match a list of strings, we would first sort the list and then send each machine
a lookup request for the strings that the machine owns. For example, if our string is "after builds
boat amaze banana", machine 1 would get a lookup request for {"after", "amaze"}.
Machine 1 looks up the documents containing "after" and "amaze' and performs an intersection on these
document lists. Machine 3 does the same for {"banana", "boat", "builds"}, and intersects their lists.
In the final step, the initial machine would do an intersection on the results from Machine 1 and Machine 3.

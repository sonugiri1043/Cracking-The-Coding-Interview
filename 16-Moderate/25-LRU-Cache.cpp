/*
  LRU Cache:
  Design and build a "least recently used" cache, which evicts the least recently used item.
  The cache should map from keys to values (allowing you to insert and retrieve a value associated
  with a particular key) and be initialized with a max size. When it is full, it should evict the least
  recently used item. You can assume the keys are integers and the values are strings.

  Solution:
  The (key, value) mapping suggests a hash table. This would make it easy to look up the value associated
  with a particular key. Unfortunately, a hash table usually would not offer a quick way to remove the most
  recently used item. We could mark each item with a timestamp and iterate through the hash table to remove
  the item with the lowest timestamp, but that can get quite slow (O(N) for insertions).

  Instead, we could use a linked list, ordered by the most recently used. This would make it easy to mark an
  item as the most recently used (just put it in the front of the list) or to remove the least recently used item
  (remove the end). Unfortunately, this does not offer a quick way to look up an item by its key. We could
  iterate through the linked list and find the item by key. But this could get very slow ( O(N) for retrieval).
  
  The linked list looks as it did in the earlier example, but now it's a doubly linked list. This allows us to easily
  remove an element from the middle of the linked list. The hash table now maps to each linked list node
  rather than the value.

  The algorithms now operate as follows:
  Inserting Key, Value Pair: Create a linked list node with key, value. Insert into head of linked list. Insert
  key -> node mapping into hash table.

  Retrieving Value by Key: Look up node in hash table and return value. Update most recently used item.
  
  Finding Least Recently Used: Least recently used item will be found at the end of the linked list.
  
  Updating Most Recently Used: Move node to front of linked list. Hash table does not need to be
  updated.

  Eviction: Remove tail of linked list. Get key from linked list node and remove key from hash table.
*/

#include <iostream>

template <typename K, typename V> class Node {
 public:
  // for head node
  Node() {
    next = NULL;
    prev = NULL;    
  }

  // for internal nodes in linked-list
  Node( K key, V value ) {
    key = key;
    value = value;
    next = NULL;
    prev = NULL;
  }

  K key;
  V value;
  Node *next;
  Node *prev;
};

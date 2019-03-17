/*
  Hash Table:
  Design and implement a hash table which uses chaining (linked lists) to handle collisions.

  To compile: 'g++ HashTableTest.cpp -o HashTableTest'
*/

#include "HashTable.h"

using std::cout;
using std::endl;

int main() {
  HashTable< string, string > *ht = new HashTable<string, string>();
  cout<< ht->get_hash( "cat" ) << endl;
  return 0;
}

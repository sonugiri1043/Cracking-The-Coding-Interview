#include "Node.h"
#include <string>
#include <functional>  // std::hash

using std::string;
using std::hash;

hash<string> strHash;

template< typename K, typename V >  class HashTable {
 public:
  HashTable() {}

  void insert( K k, V v ) {
    int index = get_hash( k ) % capacity;
    // TODO:
    // search for k,v in array[ index ]
    // if key k is found then update the value
    // otherwise add k, v at the front
  }

  void erase( K k, V v ) {
    int index =get_hash( k ) % capacity;
    // TODO
    // if k, v is found then delete it
  }

  int get_hash( K key ) {
    return strHash( key );
  }

 private:
  static const int capacity = 10;
  Node< string, string > array[ capacity ];
};

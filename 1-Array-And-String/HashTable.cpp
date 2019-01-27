/*
  HashTable.

  For real-life use-case use std::unordered_map.
 
  Unordered containers organize their elements using hash tables that allow for
  fast access to elements by their key.
 */

#include <iostream>
#include <limits>

using namespace std;

/*
 * Hash table (aka hash map) is a data structure that maps keys to values.
 * A hash table uses a hash function to compute an index into an array of slots,
 * from which the corresponding value can be found.
 *
 *   High level visualization of HashTable 
 *
 *     _____
 *    |  1  |
 *    |-----|
 *    |  2  |
 *    |-----|
 *
 *    |-----|      ________        ________
 *    |  i  |---> | Bucket |----->| Bucket |---->NULL
 *    |-----|      --------        --------
 *   
 *    |-----|
 *    | MAX |
 *     -----
 *
 *       ^
 *       |     
 *    Slots
 */

class Bucket {
public:
  Bucket( int key, int value ) : key( key ), value( value ), next( NULL ) {}

  int getKey() {
    return this->key;
  }

  Bucket * getNext() {
    return this->next;
  }

  void setNext( Bucket * next ) {
    this->next = next;
  }
  
  int getValue() {
    return this->value;
  }

  void setValue( int value ) {
    this->value = value;
  }

private:
  int key;
  int value;
  Bucket *next;
};

class HashEntry {
public:
  HashEntry( int index  ) : index( index ), next( NULL ) {}
  
  Bucket* getNext() {
    return next;
  }

  void setNext( Bucket * next ) {
    this->next = next;
  }
private:
  Bucket *next; // Pointer to list of buckets.
  int index;    // Index used to access this entry
};

class HashTable {
private:
  int HASH_SIZE;
  HashEntry **hashTable;

  int hash( int key ) {
    int index = key % HASH_SIZE;
    return index;
  }

public:
  HashTable( int size ) {
    this->HASH_SIZE = size;
    hashTable  = new HashEntry *[ HASH_SIZE ];
    for( int i = 0; i < size; i++ ) {
      hashTable[ i ] = new HashEntry( i );
    }
  }
  
  ~HashTable() {
    for( int i = 0; i < HASH_SIZE; i++ ) {
      Bucket *currBucket = hashTable[ i ]->getNext();
      Bucket *nextBucket = NULL;

      while( currBucket != NULL ) {
	// iterate through bucket list and delete all buckets
	nextBucket = currBucket->getNext();
	delete currBucket;
	currBucket = nextBucket;
      }
    }
  }

  int getValue( int key ) {
    int index = hash( key );
    Bucket *bucket = hashTable[ index ]->getNext();
    while( bucket != NULL ) {
      if( bucket->getKey() == key ) {
	return bucket->getValue();
      }
      bucket = bucket->getNext();
    }
    return INT_MIN;
  }

  void setValue( int key, int value ) {
    int index = hash( key );    
    if ( hashTable[ index ]->getNext() == NULL ) {
      Bucket *newBucket = new Bucket( key, value );
      hashTable[ index ]->setNext( newBucket );
    }

    Bucket *currBucket = hashTable[ index ]->getNext();
    while( currBucket->getNext() != NULL ) {
      // look for key in bucket list and update value
      currBucket = currBucket->getNext();
      if( currBucket->getKey() == key ) {
	currBucket->setValue( value );
	return;
      }
    }
    // key not found in bucket list, add new bucket
    Bucket *newBucket = new Bucket( key, value );
    currBucket->setNext( newBucket );
    return;
  }
};


int main() {
  cout<< "Hash Table implementation" << endl;
  
  HashTable *ht = new HashTable( 10 );
  for( int i = 0; i < 20 ; i++ ) {
    ht->setValue( i, i*2 );
  }

  for( int i = 0; i < 20 ; i++ ) {
    cout<< "Value for key " << i << " is " << ht->getValue( i ) << endl;
  }

  return 0;
}

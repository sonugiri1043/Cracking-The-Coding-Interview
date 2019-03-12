/*
  Circular Array:
  Implement a CircularArray class that supports an array-like data structure which
  can be efficiently rotated. If possible, the class should use a generic type
  ( also called a template ), and should support iteration via the standard
  for( Obj o : circularArray ) notation.
 */

template< typename T > class CircularArray {
  int capacity; // capacity of Circular array
  int size;     // size of Circular array
  int head;    // marks the..
  T *array;

 public:
 CircularArray( int capacity ) : capacity( capacity )
  {
    size = 0;
    head = -1;
    array = new T[ capacity ];
  }

  void push_back( T item ) {
    head = ( head + 1 ) % capacity;
    array[ head % capacity ] = item;
    size = ( size + 1 );
    size = size > capacity ? capacity : size;
  }

  int getSize() {
    return size;
  }
};

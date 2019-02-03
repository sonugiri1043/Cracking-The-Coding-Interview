/*
  Write a smart pointer class. A smart pointer is a data type, usually
  implemented with templates, that simulates a pointer while also
  providing automatic garbage collection. It automatically counts the
  number of references to a SmartPointer< T* > object and frees the
  object of type T when the reference count hits zero.
 */

/*
  Note:
  A smart pointer is the same as a normal pointer, but it provides safety
  via automatic memory management. It avoids issues like dangling pointers,
  memory leaks and allocation failures. The smart pointer must maintain a
  single reference count for all references to a given object.
 */

#include <iostream>

using namespace std;

template< class T > class SmartPointer {
public:
  SmartPointer( T *ptr ) {
    ref = ptr;
    ref_count = ( unsigned * ) malloc( sizeof( unsigned int ) );
    *ref_count = 1;
  }

  SmartPointer( SmartPointer<T> &sptr ) {
    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++( *ref_count );
  }

  /* Override the equal operator, so that when you set one smart
     pointer equal to another the old smart pointer has its
     reference count decremented and the new smart pointer has its
     reference count incrememented. */
  SmartPointer<T> & operator=( SmartPointer<T> & sptr ) {
    if( this == &sptr )
      return *this;
    
    /* If already assigned to an object, remove one reference. */
    if( *ref_count > 0 ) {
      remove();
    }
    
    ref = sptr.ref;
    ref_count = sptr.ref_count;
    ++( *ref_count );
    return *this;
  }

  ~SmartPointer() {
    /* We are destroying a reference to the object. Decrement ref_count.
       If ref_count is 0, then free the memory created by the integer and
       destroy the object */
    remove();
  }

  T getValue() {
    return *ref;
  }

protected:
  void remove() {
    --( *ref_count );
    if( *ref_count == 0 ) {
      delete ref;
      free( ref_count );

      ref = NULL;
      ref_count = NULL;
    }
  }

private:
  T *ref;
  unsigned *ref_count;
};

class Node {
public:
  int key;
};

int main() {
  SmartPointer< Node > nodePtr( new Node() );
  nodePtr.getValue();
  return 0;
}

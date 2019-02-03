/*
  Write an aligned malloc and free function that supports allocating
  memory such that the memory address returned is divisible by a specific
  power of two.

  EXAMPLE
  align_malloc( 1000, 128) will return a memory address that is a multiple
  of 128 and that points to memory of size 1000 bytes.

  aligned_free() will free memory allocated by align_malloc.
 */

/*
  Note:
  Typically, with malloc, we do not have control over where the memory is
  allocated within the heap. We just get a pointer to a block of memory
  which could start at any memory address within the heap.
 */

#include <iostream>

using namespace std;

void * aligned_malloc( size_t req_size, size_t alignment ) {
  size_t size = req_size +        // required size 
                alignment - 1 +   // for alignment purpose
                sizeof( void * ); // to store address for free operation

  void *p; // Initial block
  void *q; // Aligned block inside initial block

  p = (void *) malloc( size );
  if( p == NULL )
    return NULL;

  size_t reminder = (size_t) q % alignment;
  q = ( void * ) ( (size_t)p + (size_t)( alignment - reminder ) );

  // save starting address of initial block at q - 1 location
  ((void **) q )[ -1] = p;
  return q;
}

void free( void *p ) {
  void *q = ( (void **) p )[ -1 ];
  free( q );
}

int main() {
  return 0;
}

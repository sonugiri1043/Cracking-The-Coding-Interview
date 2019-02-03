/*
  Write a function in C called my2DAlloc which allocates a two-dimensional array.
  Minimize the number of calls to malloc and make sure that the memory is accessible
  by the notation arr[ i ][ j ].
 */

#include <iostream>

using namespace std;

int** my2DAllocVersion1( const int row, const int col ) {
  int **arr;
  // create a one-dimensional array of pointers
  arr = ( int** )malloc( row * sizeof(int*) );
  if( arr == NULL ) return NULL;

  for( int i = 0; i < row; i++ ) {
    // for each array index, we create a new one-dimensional array
    arr[ i ] = (int*) malloc( sizeof(int) * col );
  }
  return arr;
}

void my2DDeallocVersion1( int **ptr, int row ) {
  for( int i = 0; i < row; i++ ) {
    free( ptr[ i ] );
  }
  free( ptr );
}

int** my2DAllocVersion2( int rows, int cols ) {
  int header = rows * sizeof(int*);
  int data = rows * cols * sizeof(int);

  int** rowptr = (int**)malloc( header + data );
  if (rowptr == NULL) return NULL;
  
  int* buf = (int*) (rowptr + rows);
  for ( int i = 0; i < rows; i++ ) {
    rowptr[i] = buf + i * cols;
  }
  return rowptr;
}


int main() {
  const int row = 5;
  const int col = 6;
  int **arr = my2DAllocVersion1( row, col );
  if( arr == NULL )
    exit(1);
  arr[0][0] = 10;
  
  my2DDeallocVersion1( arr, row );

  int **arr2 = my2DAllocVersion2( row, col );
  arr2[1][1] = 20;
  return 0;
}

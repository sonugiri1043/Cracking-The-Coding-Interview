/*
  Magic Index:
  A magic index in an array A[ 0 ... n - 1 ] is defined to be an index such that A[ i ] = i.
  Given a sorted array of distinct integers, write a method to find a magic index, if one exists,
  in array A.
  FOLLOW UP
  What if the values are not distinct?
 */

#include <iostream>

using std::cout;
using std::endl;

int magicIndex( int arr[], int left, int right ) {
  if( left > right ) {
    return -1;
  }

  int mid = ( left + right )/2;
  if( arr[ mid ] == mid ) {
    return mid;
  }
  if( arr[ mid ] > mid ) {
    // search in left half
    return magicIndex( arr, left, mid - 1 );
  } else {
    // search in right half
    return magicIndex( arr, mid + 1, right );
  }
  return -1;
}

// if elements are not unique then we need to search recursively in left half and right half
// i.e. same as linear searching.

int main() {
  int arr[] = { -40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13 };
  cout<< magicIndex( arr, 0, 11 ) << endl;
  return 0;
}

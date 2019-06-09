/*
  Shortest Supersequence:

  You are given two arrays, one shorter (with all distinct elements) and one
  longer. Find the shortest subarray in the longer array that contains all the elements in the shorter
  array. The items can appear in any order.
  EXAMPLE
  Input: smallArray = { 1, 5, 9 }
         largeArray = { 7, 5, 9, 0, 2, 1, 3, '5, 7, 9, 1', 1, 5, 8, 8, 9, 7 }
  Output: [ 7, 10 ]


  Solution:
  Iterate through the largeArray backwards for each element 'e' of smallArray.
  While doing so compute and store the nextOccurance of 'e' for each element of largeArray.
  The maximum of all these nextOccurance at index i will give the closure at index i.
  
  Compute the minimum diff between index and maximum value of nextOccurance to get min sub-array
  which contain all elements of smallArray.
*/

// g++ 18-Shortest-Supersequence.cpp --std=c++11

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void getShortestSupersequence( vector<int> smallArray, vector<int> largeArray ) {
  size_t size = largeArray.size();
  vector<int> nextOccurence( size,0 );
  for( auto k : smallArray ) {
    int index = -1;
    for( int i = size - 1; i >= 0; --i ) {
      if( largeArray[i] == k ) {
	index = i;
      }
      if( index == -1 || nextOccurence[ i ] == -1 ) {
	nextOccurence[ i ] = -1;
      } else if( index > nextOccurence[ i ] ) {
	// we are only interested in knowing the max next occurance among all k's
	nextOccurence[ i ] = index;
      }
    }
  }
  int min = size;
  int left = 0;
  int right = size - 1;
  for( int i = 0; i < size; ++i ) {
    if( nextOccurence[ i ] == -1 ) {
      continue;
    } else if( nextOccurence[ i ] - i < min ) {
      min = nextOccurence[ i ] - i;
      left = i;
      right = nextOccurence[ i ];
    }
  }
  cout<< "Left index:" << left << " right index:" << right << endl;
}

int main() {
  vector<int> smallerArray = { 1, 5, 9};
  vector<int> largeArray = { 7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7 };
  getShortestSupersequence( smallerArray, largeArray );
  return 0;
}

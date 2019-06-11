/*
  Letters and Numbers:
  Given an array filled with letters and numbers, find the longest subarray with an equal
  number of letters and numbers.

  All letters are treated identically and all numbers are treated identically. Therefore,
  we can use an example with a single letter and a single number -or, for that matter,
  As and Bs, Os and 1s.
  Example: [ A, B, A, A, A, B, B, B, A, B, A, A, B, B, A, A, A, A, A, A ]

  We're looking for the smallest subarray where count( A, subarray ) = count( B, subarray ).

  Brute Force:
  Just go through all subarrays, count the number of As and Bs (or letters and numbers), and
  find the longest one that is equal. We can make one small optimization to this. We can start
  with the longest subarray and, as soon as we find one which fits this equality condition, return it.
  O( N^2 ).

  Optimal Solution:
  
           A, B, A, A, A, B, B, B, A, B, A, A, B, B, A, A,  A,  A,  A,  A
  count A: 1  1  2  3  4  4  4  4  5  5  6  7  7  7  8  9  10  11  12  13
  count B: 0  1  1  1  1  2  3  4  4  5  5  5  6  7  7  7   7   7   7   7
  Diff:    1  0  1  2  3  2  1  0  1  0  1  2  1  0  1  2   3   4   5   6

  
  Whenever we return the same difference, then we know we have found an equal subarray. To find the
  biggest subarray, we just have to find the two indices farthest apart with the same value.

  Alternate Solution:
  Replace A with 1 and B with -1. Use kudane algo to find longest array with 0 sum.

*/

// g++ 5-Letters-And-Numbers.cpp --std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

vector<int> computeDelta( vector<int> arr ) {
  int onesCount = 0;
  int zerosCount = 0;
  vector<int> diff( arr.size() );
  for( int i=0; i < arr.size(); ++i ) {
    if( arr[i] == 1 ) {
      ++onesCount;
    } else {
      ++zerosCount;
    }
    diff[i] = onesCount - zerosCount;
  }
  return diff;
}

std::pair<int, int> findLongesMatch( vector<int> delta ) {
  std::pair<int, int> max = std::make_pair( 0, 0 );
  unordered_map<int, int> map;
  map.insert( std::make_pair( 0, -1) ); // diff = 0 initially
  for( int i = 0; i < delta.size(); ++i ) {
    if( map.find( delta[i] ) == map.end() ) {
      map.insert( std::make_pair( delta[i], i ) );
    } else {
      int index =  map[ delta[i] ];
      int dist = i - index;
      if( dist > max.second - max.first ) {
	max = std::make_pair( index, i );
      }
    }
  }
  return max;
}

std::pair<int, int> getMaxSubArrayWithSameAandB( vector<int> arr ) {
  vector<int> delta = computeDelta( arr );
  std::pair<int, int> max = findLongesMatch( delta );
  return max;
}

int main() {
  vector<int> arr = { 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0,  0,  0,  0,  0 };
  getMaxSubArrayWithSameAandB( arr );
  return 0;
}

/*
  Majority Element:
  A majority element is an element that makes up more than half of the items in an array.
  Given a positive integers array, find the majority element. If there is no majority element,
  return -1. Do this in O( N) time and O( 1) space.

  Input: 1 2 5 9 5 9 5 5 5
  Output: 5

  Solution:
  The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence
  of elements using linear time and constant space.
  The algorithm finds a majority element, if there is one: that is, an element that occurs repeatedly
  for more than half of the elements of the input. However, if there is no majority, the algorithm will
  not detect that fact, and will still output one of the elements. A version of the algorithm that makes
  a second pass through the data can be used to verify that the element found in the first pass really is
  a majority.

  Initialize an element m and a counter i with i = 0
  For each element x of the input sequence:
     If i = 0, then assign m = x and i = 1
     else if m = x, then assign i = i + 1
     else assign i = i − 1
  Return m
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int getMajorityElement( vector<int> input ) {
  if( input.size() == 1 ) {
    return input[0];
  }
  int majoritySuspect = input[0];
  int count = 1;
  for( int i=1; i < input.size(); i++ ) {
    if( input[i] == majoritySuspect ) {
      ++count;
    } else {
      --count;
      if( count <= 0 ) {
	majoritySuspect = input[i];
      }
    }
  }

  // verify majority element
  count = 0;
  for( auto v : input )  {
    if( v == majoritySuspect )
      count++;
  }
  if( count > input.size()/2 ) {
    cout<< "Majority element found" << endl;
  }
  return majoritySuspect;
}

int main() {
  vector<int> input = { 1, 2, 5, 9, 5, 9, 5, 5, 5 };
  cout<< getMajorityElement( input ) << endl;
  return 0;
}

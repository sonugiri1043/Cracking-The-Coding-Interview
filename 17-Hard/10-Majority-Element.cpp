/*
  Majority Element:
  A majority element is an element that makes up more than half of the items in an array.
  Given a positive integers array, find the majority element. If there is no majority element,
  return -1. Do this in O( N) time and O( 1) space.

  Input: 1 2 5 9 5 9 5 5 5
  Output: 5
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

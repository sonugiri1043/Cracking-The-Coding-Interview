/*
  Majority Element:
  A majority element is an element that makes up more than half of the items in an array.
  Given a positive integers array, find the majority element. If there is no majority element,
  return -1. Do this in O( N) time and O( 1) space.

  Input: 1 2 5 9 5 9 5 5 5
  Output: 5

  Solution: Boyer–Moore majority vote algorithm
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


  Number which appears more than n/3 times in an array

  Start with two empty candidate slots and two counters set to 0.
  for each item:
     if it is equal to either candidate, increment the corresponding count
     else if there is an empty slot (i.e. a slot with count 0), put it in that slot and set the count to 1
     else reduce both counters by 1
   At the end, make a second pass over the array to check whether the candidates really do have the required count.


  This can easily be extended to:
  Given an array of size n and a number k, find all elements that appear more than n/k times.

  Solution:
  1.Create a temporary array of size (k-1) to store elements and their counts.
  2.Traverse through the input array and update temp[] (add/remove an element or increase/decrease count)
    for every traversed element.
  3.Iterate through final (k-1) potential candidates (stored in temp[]). or every element, check if it
    actually has count more than n/k.
    
   what to do when temp[] is full and we see a new element – we decrease count of every element by 1 in temp[].
   If the count reaches zero then we remove an element.
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

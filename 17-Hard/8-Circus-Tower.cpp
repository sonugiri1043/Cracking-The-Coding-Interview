/*
  Circus Tower:
  A circus is designing a tower routine consisting of people standing atop one another's
  shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than
  the person below him or her. Given the heights and weights of each person in the circus, write a
  method to compute the largest possible number of people in such a tower.

  Solution:
  The problem is really the following:
  We have a list of pairs of items. Find the longest sequence such that both the first and second
  items are in non-decreasing order.
  
  1. Sort the heights in decreasinn order.
  2. Now in the sorted array find the longest decreasing weight sub-array.
 */

// g++ 8-Circus-Tower.cpp --std=c++11

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool compHeight( const std::pair<int, int> a, const std::pair<int, int> b ) {
  return a.first > b.first;
}

int longestIncreasingWeight( vector< std::pair<int, int> > htWtPairs ) {
  int globalLongest = 1;
  int longest = 1;
  for( int i = 1; i < htWtPairs.size(); i++ ) {
    if( htWtPairs[i].second < htWtPairs[i-1].second ) {
      longest += 1;
      if( longest > globalLongest ) {
	globalLongest = longest;
      }
    } else {
      longest = 1;
    }
  }
  return globalLongest;
}

int getLongestHtAndWt( vector< std::pair<int, int> > htWtPairs ) {
  std::sort( htWtPairs.begin(), htWtPairs.end(), compHeight );
  return longestIncreasingWeight( htWtPairs );
}

int main() {
  vector< std::pair<int, int> > heightAndWeight = { {65, 100}, {70, 150}, {56, 90}, {75, 190},
						    {60,85}, {68,110} };
  cout<< getLongestHtAndWt( heightAndWeight ) << endl;
  vector< std::pair<int, int> > heightAndWeight1 = {{1,1}, {3,3}, {7,2}, {6,4}, {9,9}, {8,5}};
  cout<< getLongestHtAndWt( heightAndWeight1 ) << endl;
  return 0;
}

/*
  Random Set:
  Write a method to randomly generate a set of m integers from an array of size n. Each
  element must have equal probability of being chosen.
 */

#include <iostream>
#include <vector>
#include <cstdlib> // rand
#include <set>

using std::vector;
using std::set;


set<int> getMRandomFromN( vector< int > v, int m ) {
  int randIndex;
  int tmp;
  int size = v.size();
  for( int i=0; i < m; ++i ) {
    randIndex = i + rand() % ( size - i );
    // move tmp to ith location
    tmp = v[ randIndex ];
    v[ randIndex ] = v[ i ];
    v[ i ] = tmp;
  }
  
  set< int > s;
  for( int i = 0; i < m; ++i ) {
    s.insert( v[i] ); 
  }
  return s;
}

int main() {
  return 0;
}

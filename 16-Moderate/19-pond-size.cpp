/* Pond Sizes:
   You have an integer matrix representing a plot of land, where the value at that location
   represents the height above sea level. A value of zero indicates water. A pond is a region
   of water connected vertically, horizontally, or diagonally. The size of the pond is the total
   number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.

EXAMPLE

Input:

0 2 1 0
0 1 0 1
1 1 0 1
0 1 0 1

  Output: 2, 4, 1 (in any order)
*/

// g++ 19-pond-size.cpp --std=c++14

#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::set;

int getSize( vector< vector<int> > &arr, int row, int col ) {
  if( row < 0 || col < 0 || row >= arr.size() || col >= arr.size() ) {
    return 0;
  }
  if( arr[ row ][ col ] != 0 ) {
    return 0;
  }
  int size = 1;
  arr[ row ][ col ] = -1;
  for( int i=-1; i <= 1; i++ ) {
    for( int j=-1; j <= 1; j++ ) {
      size += getSize( arr, row + i, col + j );
    } 
  }
  return size;
}

set<int> pondSize( vector< vector<int> > arr ) {
  set<int> sizes;
  for( int i = 0; i < arr.size(); ++i ) {
    for( int j = 0; j < arr[i].size(); ++j ) {
      if( arr[ i ][ j ] == 0 ) { 
	sizes.insert( getSize( arr, i, j ) );
      }
    } 
  }
  return sizes;
}

int main() {
  vector< vector< int > > arr = { { 0, 2, 1, 0 }, { 0, 1, 0, 1 }, { 1, 1, 0 ,1 }, { 0, 1, 0, 1 } };
  set< int > res = pondSize( arr );
  for( auto s : res ) {
    cout<< s << endl;
  }
  return 0;
}

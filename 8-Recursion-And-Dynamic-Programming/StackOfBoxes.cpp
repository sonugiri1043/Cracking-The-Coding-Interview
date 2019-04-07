/*
  Stack of Boxes:
  You have a stack of n boxes, with widths Wi heights hi and depths di.
  The boxes cannot be rotated and can only be stacked on top of one another if each box
  in the stack is strictly larger than the box above it in width, height, and depth.

  Implement a method to compute the height of the tallest possible stack. The height of a
  stack is the sum of the heights of each box.
 */

#include <iostream>
#include <vector>

using std::vector;

// assume we have sorted boxes on height
int maxHeight( int numBoxes, vector<int> &height, vector<int> &width, vector<int> & depth ) {
  int maxHeight[ numBoxes] = { 0 };
  for( int i=0; i< numBoxes; ++i ) {
    maxHeight[i] = height[i ];
  }
  for( int i=1; i < numBoxes; ++i ) {
    int h = 0;
    for( int j=0; j < i; ++j ) {
      if( height[ i ] > height[ j ] &&
	  width[ i ] > widht[ j ] &&
	  depth[ i ] > depth[ j ] ) {
	h = maxHeight[ i ] + maxHeight[ j ];
      }
    }
    if( h > maxHeight[ i ] ) {
      maxHeight[ i ] = h;
    }
  }
}

int main() {
  int numBoxes = 100;
  vector< int > height;
  vector< int > width;
  vector< int > depth;
  for( int i=0; i< numBoxes; i++ ) {
    // put some numbers for testing
    height.push_back( 0 );
    width.push_back( 0 );
    depth.push_back( 0 );
  }
  maxHeight( numBoxes, height, width, depth );
  return 0;
}

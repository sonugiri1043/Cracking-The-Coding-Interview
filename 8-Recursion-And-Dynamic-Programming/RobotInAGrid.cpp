/*
  Robot in a Grid:
  Imagine a robot sitting on the upper left corner of grid with r rows and c columns.
  The robot can only move in two directions, right and down, but certain cells are
  "off limits" such that the robot cannot step on them. Design an algorithm to find
  a path for the robot from the top left to the bottom right.
 */

#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::set;
using std::make_pair;

int numRow = 10;
int numCol = 10;
bool arr[ 10 ][ 10 ];

bool findPath( int rowNo, int colNo ) {
  if( !arr[rowNo][colNo] ) {
    return false;
  }
  if( rowNo >= numRow ||
      colNo >= numCol ) {
    return false;
  }
  if( ( rowNo == numRow - 1 ) &&
      ( colNo == numCol - 1 ) ) {
    cout<< "Reached destinaiton" << endl;
    return true;
  }
  if( findPath( rowNo, colNo + 1 ) || // move right
      findPath( rowNo + 1, colNo ) ) {
    return true;
  }
  return false;
}


/* O( numRow*numCol ) time*/
bool findPathV2( int rowNum, int colNum, vector< pair<int,int> > &path,
		 set< pair<int, int> > &failedPoints ) {
  if( rowNum >= numRow || colNum >= numCol || !arr[ rowNum ][ colNum ] ) {
    return false;
  }
  pair<int, int> p = make_pair( rowNum, colNum );
  if( failedPoints.find( p ) != failedPoints.end() ) {
    // ( rowNum, colNum ) leads to no-path
    return false;
  }
  if( rowNum == numRow - 1 &&
      colNum == numCol - 1 ) {
    path.push_back( p );
    return true;
  }
  if( findPathV2( rowNum + 1, colNum, path, failedPoints ) ||
      findPathV2( rowNum, colNum + 1, path, failedPoints ) ) {
    path.push_back( p );
    return true;
  }
  failedPoints.insert( p );
  return false;
}

int main() {
  return 0;
}

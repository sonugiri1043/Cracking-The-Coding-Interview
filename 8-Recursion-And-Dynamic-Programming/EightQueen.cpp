/*
  Eight Queens:
  Write an algorithm to print all ways of arranging eight queens on an 8x8
  chess board so that none of them share the same row, column, or diagonal.
  In this case, "diagonal" means all diagonals, not just the two that bisect
  the board.

  Note: Eight queens puzzle has 92 distinct solutions.
*/

#include <iostream>
#include <vector>
#include <cstdlib> // abs

using std::cout;
using std::endl;
using std::vector;

bool checkValid( int rowNum, int colNum, vector< int > &columns ) {
  /*
    Check if ( rowNum, colNum ) is a valid spot for a queen by checking if
    there is a  queen in the same col or diagonal. We don't need to check
    it for queens in the same row because the calling placeQueen only attempts
    to place one queen at a time. We know this row is empty.
   */
  for( int row=0; row<rowNum; row++ ) {
    if( columns[ row ] == colNum )
      return false; // placed in same columns

    // Check diagonal: If the distance between the columns equals the distance
    // between the rows, then they're in the same diagonal.
    if( abs( rowNum - row ) == abs( colNum - columns[ row ] ) ) {
      return false;
    }
  }
  return true;
}

void placeQueen( int rowNum, int gridSize, vector< int > &columns ) {
  if( rowNum == gridSize ) {
    cout<< "Valid queen placements" << endl;
    for( int i = 0; i < gridSize; i++ ) {
      cout<< columns[ i ] << endl;
    }
    return;
  }
  for( int col = 0; col < gridSize; col++ ) {
    if( checkValid( rowNum, col, columns ) ) {
      columns[rowNum] = col;
      placeQueen( rowNum + 1, gridSize, columns );
    }
  } 
}

int main() {
  static int gridSize = 8;
  // We don't need nxn array to store the position of queens. Instead we can store
  // the columns no for each row.
  vector< int > columns;
  for( int i = 0; i < gridSize; i++ ) {
    columns.push_back( 0 );
  }
  placeQueen( 0, gridSize, columns );
  return 0;
}

/*
  Max Submatrix: Given an NxN matrix of positive and negative integers, write code to find the
  submatrix with the largest possible sum.

  sum( 0, 0, a, b ) = max( sum( 0, 0, a-1, b ) + sum( a-1, 0, a, b ),
                           sum( 0, 0, a, b-1 ) + sum( 0, b-1, a, b ),
			   sum( a-1, 0, a, b ),
			   sum( 0, b-1, a, b ) )
 */

#include <iostream>
#include <climits>

using std::cout;
using std::endl;

int getSum( int arr[][5], int rStart, int rEnd, int cStart, int cEnd ) {
  if( rStart < 0 || cStart < 0 ) {
    return 0;
  }
  int sum = 0;
  for( int i = rStart; i <= rEnd; i++ ) {
    for( int j = cStart; j <= cEnd; j++ ) {
      sum += arr[i][j];
    }
  }
  return sum;
}

int getMaxSubMatrixBruteForce( int arr[][5], int row, int col ) {
  int sum = 0;
  int maxSoFar = INT_MIN;
  for( int srow = 0; srow < row; srow++ ) {
    for( int erow = srow; erow < row; erow++ ) {
      for( int scol = 0; scol < col; scol++ ) {
	for( int ecol = scol; ecol < col; ecol++  ){
	  sum = getSum( arr, srow, erow, scol, ecol );
	  if( maxSoFar < sum ) {
	    maxSoFar = sum;
	  }
	}
      }
    }
  }
  return maxSoFar;
}

int main() {
  int arr[4][5] = { { 1, 2, -1, -4, -20 },
		  { -8, -3, 4, 2, 1 },
		  { 3, 8, 10, 1, 3 },
		  { -4, -1, 1, 7, -6 } };
  cout << getMaxSubMatrixBruteForce( arr, 4, 5 ) << endl;
  cout << getMaxSubMatrix( arr, 4, 5 ) << endl;
  return 0;
}

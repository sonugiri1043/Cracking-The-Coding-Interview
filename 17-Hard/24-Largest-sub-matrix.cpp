/*
  Max Submatrix: Given an NxN matrix of positive and negative integers, write code to find the
  submatrix with the largest possible sum.
 */

// g++ 24-Largest-sub-matrix.cpp --std=c++14

#include <iostream>
#include <vector>
#include <climits> // INT_MIN

using std::cout;
using std::endl;
using std::vector;

/****************************************************************************/
// BRUTE FORCE APPROACH
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
  int maxLeft;
  int maxRight;
  int maxUp;
  int maxDown;
  for( int srow = 0; srow < row; srow++ ) {
    for( int erow = srow; erow < row; erow++ ) {
      for( int scol = 0; scol < col; scol++ ) {
	for( int ecol = scol; ecol < col; ecol++  ){
	  sum = getSum( arr, srow, erow, scol, ecol );
	  if( maxSoFar < sum ) {
	    maxSoFar = sum;
	    maxLeft = srow;
	    maxRight = erow;
	    maxUp = scol;
	    maxDown = ecol;
	  }
	}
      }
    }
  }
  cout<< "Max Sum: " << maxSoFar << endl;
  cout<< "Row:" << maxLeft << "-" << maxRight << " Col:" << maxUp << "-" << maxDown << endl;
  return maxSoFar;
}
/***************************************************************************************/

int kadaneAlgo( vector<int> v, int &start, int &end ) {
  if( v.size() == 1 ) {
    start = 0;
    end = 0;
    return v[0];
  } 

  int maxSum = INT_MIN;  
  int sum = v[0];
  int localStart = 0;
  int localEnd = 0;
  for( int i = 1; i < v.size(); ++i ) {
    if( v[i] + sum > v[i] ) {
      sum += v[i];
      localEnd = i;
    } else {
      sum = v[i];
      localStart = i;
    }

    if( sum > maxSum ) {
      start = localStart;
      end = localEnd;
      maxSum = sum;
    }
  }
  cout<< "Max sum: " << maxSum << " start:" << start << " end:" << end << endl;
  return maxSum;
}

int getMaxSubMatrixSum( int arr[][5], int row, int col ) {
  int maxSum = INT_MIN;
  int top, bottom, left, right; // position of sub-matrix
  for( int i = 0; i < col; i++ ) {
    for( int j = i; j < col; j++ ) {
    }
  }
  return maxSum;
}

int main() {
  int arr[4][5] = { { 1, 2, -1, -4, -20 },
		    { -8, -3, 4, 2, 1 },
		    { 3, 8, 10, 1, 3 },
		    { -4, -1, 1, 7, -6 } };
  cout<< "-------------Brute Force approach----------" << endl;
  cout << getMaxSubMatrixBruteForce( arr, 4, 5 ) << endl;

  cout<< "---------------Kadane Algo test ------------" << endl;
  int start;
  int end;
  vector<int> v1 = {-8, -3, 4, 2, 1};
  vector<int> v2 = { -4, -1, 1, 7, -6 };
  kadaneAlgo( v1, start, end );
  kadaneAlgo( v2, start, end );
  cout << "Max sub-matix sum using kadane algo." << endl;
  //cout << getMaxSubMatrixSum( arr, 4, 5 ) << endl;
  return 0;
}

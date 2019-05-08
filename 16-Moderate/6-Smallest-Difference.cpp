/*
  Smallest Difference:
  Given two arrays of integers, compute the pair of values (one value in each
  array) with the smallest (non-negative) difference. Return the difference.
  EXAMPLE
  Input { 1, 3, 15, 11,2 }, {23, 127, 235, 19, 8}
  Output 3. That is, the pair (11, 8).

  A optimal approach is to sort the arrays. Once the arrays are sorted, we can
  find the minimum difference by iterating through the array.

  Consider the following two arrays:
  A: { 1, 2, 11, 15 }
  B: { 4, 12, 19, 23, 127, 235 }

  Try the following approach:
  1.Suppose a pointer a points to the beginning of A and a pointer b points to the
    beginning of B. The current difference between a and b is 3. Store this as the min.
  2.How can we ( potentially ) make this difference smaller? Well, the value at b is bigger
    than the value at a, so moving b will only make the difference larger. Therefore,
    we want to move a.
  3.Now a points to 2 and b (still) points to 4. This difference is 2, so we should update min.
    Move a, since it is smaller.
  4.Now a points to 11 and b points to 4. Move b.
  5.Now a points to 11 and b points to 12. Update min to 1. Move b.
  
  And so on.
 */


// Compile using 'g++ 6-Smallest-Difference.cpp --std=c++14'
#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

int smallestDiff( vector<int> A, vector<int> B ) {
  // sort in ascending order
  std::sort( A.begin(), A.end() );
  std::sort( B.begin(), B.end() );
  
  int i = 0, j = 0;
  int diff = INT_MAX;
  int tmpDiff;
  while( i < A.size() && j < B.size() ) {
    if ( A[i] > B[j] ) {
      tmpDiff = A[i] - B[j];
      j = j + 1;
    } else {    
      tmpDiff = B[j] - A[i];
      i = i + 1; 
    }
    if( tmpDiff < diff ) {
      diff = tmpDiff;
    }
  }
  return diff;
}

int main() {
  vector<int> A = { 1, 2, 11, 15 };
  vector<int> B = { 4, 12, 19, 23, 127, 235 };
  cout<< smallestDiff( A, B ) << endl;
  return 0;
}

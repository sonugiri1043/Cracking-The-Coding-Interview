/*
  Sub Sort:
  Given an array of integers, write a method to find indices m and n such that if you sorted
  elements m through n, the entire array would be sorted. Minimize n - m (that is, find the
  smallest such sequence).
  EXAMPLE
  Input: 1, 2, 4, 7, 10, 11, 8, 12, 5, 6, 16, 18, 19
  Output: (3, 9)

  Solution:
  1. Get the increasing sequence from the left side( index 0 ), seqLeft .
  2. Get the decreasing sequence from right side( index size()-1 ), seqRight.
  3. Get the min element in middle sequence and right.
  4. Get the max element in middle sequence and left.
  5. Position of min in left seq and position of max in right seq would be the result.
 */

// g++ 16-Sub-Sort.cpp --std=c++14

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void subSort( vector<int> v ) {
  int leftSeq = 0;
  for( int i = 1; i < v.size(); ++i ) {
    if( v[i] >= v[ i-1 ] ) {
      ++leftSeq;
      continue;
    }
    break;
  }
  if( leftSeq == v.size() - 1 ) {
    cout<< "already increasing sequence" << endl;
    return;
  }
  cout<< "Left seq index:" << leftSeq << endl;


  int rightSeq = v.size() - 1;
  for( int i = v.size() - 2; i >= 0; --i ) {
    if( v[i] <= v[ i + 1 ] ) {
      --rightSeq;
      continue;
    }
    break;
  }
  cout<< "Right seq index:" << rightSeq << endl;

  int minNo = v[ leftSeq ];
  for( int i = leftSeq+1; i < rightSeq; i++ ) {
    if( v[ i ] < minNo ) {
      minNo = v[i];
    }
  }
  int maxNo = v[ rightSeq ];
  for( int i = rightSeq-1; i > leftSeq; --i ) {
    if( maxNo < v[ i ] ) {
      maxNo = v[i];
    }
  }
  cout<< maxNo << " " << minNo << endl;
  
  // now find the index of minNo in leftSeq and index of maxNo in rightSeq
  for( int i = 0; i <= leftSeq; i++ ) {
    if( minNo < v[i] ) {
      cout<< "Left index: " << i <<  endl;
      break;
    }
  }
  for( int i = rightSeq; i < v.size(); i++ ) {
    if( maxNo < v[i] ) {
      cout<< "Right index:" << i - 1 << endl;
      break;
    }
  }
}

int main() {
  vector< int > v1 = {1, 2, 3, 3, 4, 6, 7};
  vector<int> v2 = { 1, 2, 4, 7, 10, 11, 8, 6, 12, 5, 6, 16, 18, 19 };
  subSort( v1 );
  subSort( v2 );
  return 0;
}

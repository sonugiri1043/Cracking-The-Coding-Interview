/*
  Contiguous Sequence:
  You are given an array of integers (both positive and negative). Find the contiguous
  sequence with the largest sum. Return the sum.

EXAMPLE

Input 2, -8, 3, -2, 4, -10

Output: 5 ( i.e. { 3, -2, 4 } )
*/

// g++ 17-Contigous-Sequence.cpp --std=c++14

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int largestContigousSeq( vector<int> seq ) {
  vector<int> subSeqAtPos( seq.size() );
  subSeqAtPos[0]= seq[0];
  for( int i=1; i < seq.size(); ++i ) {
    subSeqAtPos[i] = seq[i] >= ( subSeqAtPos[i-1] + seq[i] )? seq[i] : subSeqAtPos[ i -1 ] + seq[i];
  }
  
  int max=subSeqAtPos[0];
  for( int i=1; i < seq.size(); ++i ) {
    max = max > subSeqAtPos[i] ? max : subSeqAtPos[i];
  }
  return max;
}

int main() {
  vector< int > seq = { 2, -8, 3, -2, 4, -10 };
  cout<< largestContigousSeq( seq ) << endl;
  return 0;
}

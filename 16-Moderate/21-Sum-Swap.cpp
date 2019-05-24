/*
  Sum Swap:
  Given two arrays of integers, find a pair of values (one value from each array) that you
  can swap to give the two arrays the same sum.

  EXAMPLE
  Input:{4, 1, 2, 1, 1, 2} and {3, 6, 3, 3}
  Output: {1, 3}
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

void findPairWithDiff( vector<int> v1, vector<int> v2, int diff ) {
  unordered_map<int, bool> hashMap;
  for( auto i : v2 ) {
    hashMap[ i ] = true;
  }
  
  for( auto i : v1 ) {
    if( hashMap.find( diff - i ) != hashMap.end() ) {
      cout<< i << " " << diff - i << endl;
    }
  }
}

void sumSwap( vector<int> v1, vector<int> v2 ) {
  // 1. Get sum of both vector v1 and v2.
  // 2. Find the difference in sum.
  // 3. Find a pair v2, v1 whose diff is -sum.
  vector<int>::iterator it;
  int sumV1 = 0, sumV2 = 0;
  for( it = v1.begin(); it != v1.end(); ++it ) {
    sumV1 += *it;
  }
  for( it = v2.begin(); it != v2.end(); ++it ) {
    sumV2 += *it;
  }
  int diff = sumV2 - sumV1;
  findPairWithDiff( v1, v2, diff );
}

int main() {
  vector<int> v1 = { 4, 1, 2, 1, 1, 2 };
  vector<int> v2 = { 3, 6, 3, 3 };
  sumSwap( v1, v2 );
  return 0;
}

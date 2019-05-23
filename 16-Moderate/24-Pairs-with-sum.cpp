/* Pairs with Sum:
   Design an algorithm to find all pairs of integers within an array which sum to a
   specified value.

   Sol1: Use hashmap.
   Sol2: Sort and find matching pair.
*/

// g++ 24-Pairs-with-sum.cpp --std=c++14

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

void findPairWithSum( vector< int > v, int sum ) {
  unordered_map< int, int > ht;
  for( auto i : v ) {
    // add int in vector to hashmap, also keep their count
    if( ht.find( i ) != ht.end() ) {
      ht[ i ]++;
    } else {
      ht[ i ] = 1;
    }
  }

  for( auto i : v ) {
    if( ht.find( sum - i ) != ht.end() ) {
      // to handle duplicates decrease count once a key has been considered
      // remove if count becomes 0
      ht[ i ] -= 1;
      ht[ sum - i ] -= 1;
      if( ht[ i ] == 0 ) {
	ht.erase( i );
      }
      if( ht[ sum - i ] == 0 ) {
	ht.erase( sum - i );
      }

      cout<< i << " " << sum - i << endl;
    }
  }
}

int main() {
  vector<int> v = { -1, 14, 1, 13, 5, 6, 3, 9, -3, -2 };
  int target = 10;
  findPairWithSum( v, target );
  return 0;
}

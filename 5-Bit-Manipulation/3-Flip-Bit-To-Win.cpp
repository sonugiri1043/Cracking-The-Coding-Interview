// compile using 'g++ 3-Flip-Bit-To-Win.cpp -o 3-Flip-Bit-To-Win --std=c++14'

/* Flip Bit to Win:
   You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to
   find the length of the longest sequence of 1 s you could create.
   EXAMPLE
   Input: 1775 ( or: 11011101111 )
   Output: 8  */

#include <iostream>
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;

#include <vector>
using std::vector;

int longestSequestOf1s( int n ) {
  // Step 1: Convert integer n into an array that reflects the lengths of the
  // Os and 1 s sequences.

  int tmp = n;
  int len = 0;
  vector< pair< int, int > > lengthOfSubSeq;

  int zeros = 0;
  int ones = 0;
  while( len < 32  ) {
    if( ( tmp & 1 ) == 1 ) {
      if( zeros != 0 ) {
	lengthOfSubSeq.push_back( make_pair( 0, zeros ) );
	zeros = 0;
      }
      ones += 1;
    } else {
      if( ones != 0 ) {
	lengthOfSubSeq.push_back( make_pair( 1, ones ) );
	ones = 0;
      }
      zeros += 1;
    }
    len++;
    tmp = tmp >> 1;
  }
  
  if( zeros )
    lengthOfSubSeq.push_back( make_pair( 0, zeros ) );
  else
    lengthOfSubSeq.push_back( make_pair( 0, ones ) );


  // step2 : Get the max seq we can get by flipping one zero to 1.
  int prev = 0;
  int max1s = 0;
  for( pair<int, int> xy : lengthOfSubSeq ) {
    if( xy.first == 1 ) {
      if( max1s < prev + xy.second )
	max1s = prev + xy.second;
      prev = xy.second;
    } else {
      if( xy.second != 1 ) {
	prev = 0; // set prev to 0 if seq is 0 length is more than 1.
      } else {
	prev = prev + 1;
      }
    }
  }
  return max1s;
}

int main() {
  cout << longestSequestOf1s( 1775 ) << endl;
  return 0;
}

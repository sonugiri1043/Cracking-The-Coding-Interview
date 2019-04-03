/*
  Permutations with Dups:
  Write a method to compute all permutations of a string whose characters are not
  necessarily unique. The list of permutations should not have duplicates.
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void getAllPermutations( string input ) {
  vector< string > currPerm = { input.substr( 0, 1) }; // base case with 1 element [ { 'a' } ]
  vector< string > nextPerm;

  for( int i = 1; i < input.length(); i++ ) {
    for( auto it = currPerm.begin(); it != currPerm.end(); ++it ) { 
      // for each permutation 'it' of length i append input[i+1] at all places in
      // 'it' to get permutation of length 'i+1'
      string s = *it;
      for( int j = 0; j <= s.length(); ++j ) {
	if( ( j > 0 ) && ( input[ i ] == input[ j - 1 ]  ) ) {
	  // check to see if this element is already duplicate of adjacement element
	  continue;
	}
	string tmp = s.substr( 0, j ) + input[ i ] + s.substr( j, s.length() );
	nextPerm.push_back( tmp );
      }
    }
    currPerm = nextPerm;
    nextPerm.clear();
  }
  for( auto it = currPerm.begin(); it != currPerm.end(); ++it ) {
    cout<< *it << endl;
  }
}

int main() {
  string input = "aabcd";
  getAllPermutations( input ); // should print 60 permutations n!/noOfRep!
  return 0;
}

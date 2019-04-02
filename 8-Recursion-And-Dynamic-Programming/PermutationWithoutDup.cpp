/*
  g++ PermutationWithoutDup.cpp -o test --std=c++14
*/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void getAllPermutations( string input ) {
  vector< string > currPerm = { input.substr(0,1) }; // base case
  vector< string > nextPerm;

  for( int i = 1; i < input.length(); i++ ) {
    for( auto it = currPerm.begin(); it != currPerm.end(); ++it ) {
      // for each permuation of size i put input[ i + 1 ] at each position
      // thus obtaining permuation of size i+1 
      string s = *it;
      for( int j = 0; j <= s.length(); ++j ) {
	string tmp = s.substr( 0, j ) + input[ i ] + s.substr( j, s.length() );
	nextPerm.push_back( tmp );
      }
    }
    currPerm = nextPerm;
    nextPerm.clear();
  }

  // print permutation of size input.length()
  for( auto it = currPerm.begin(); it != currPerm.end(); ++it ) {
    cout<< *it << endl;
  }
}

int main() {
  string input = "abcd";
  getAllPermutations( input );
  return 0;
}

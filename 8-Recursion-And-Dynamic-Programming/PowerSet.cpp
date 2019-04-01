// g++ PowerSet.cpp -o <output-file> --std=c++14

/*                                                                                                                                           
  Power Set: Write a method to return all subsets of a set.                                                                                  
                                                                                                                                             
  Solution:                                                                                                                                  
  When we generate a subset, each element has the "choice" of either being in there                                                          
  or not. So doing { 2 * 2 * 2 ... } n times gives us 2^n subsets.                                                                           
                                                                                                                                             
  There are 2^n subsets and each of n elements will be contained in half of the subsets                                                      
  ( which is 2^n-1 ). Therefore, the total nuber of elements across all of those                                                             
  subsets is n * 2^(n-1).                                                                                                                    
                                                                                                                                             
  Space/Time complexity: O( n2^n ).                                                                                                          
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::list;

void getPowerSetV1( vector< char > & origSet ) {
  // Iterate through all no's from 0 - (2^(n)-1).
  // For each no if ith bit is set then include ith element from original set
  int noOfSets = 1 << origSet.size();
  for( int i=0; i < noOfSets; i++ ) {
    for( int j=0; j < origSet.size(); j++ ) {
      if( i & ( 1 << j ) ) {
	cout<< origSet[ j ] << " ";
      } else {
	cout<< "  ";
      }
    }
    cout<< endl;
  }
}

void getPowerSetV2( vector< char > & origSet ) {
  /*
    p( 0 ) = {}
    p( 1 ) = {}, {a}
    p( 2 ) = {}, {a}, {b}, {a,b}
    p(n) = p(n-1) + nth element appended to all sets of size p(n-1)
   */
  list<list<char>> powerSet;
  powerSet = { {} };
  for( int i = 1; i <= origSet.size(); i++ ) {
    list<list<char>> tmpPowerSet;
    list<char> tmp;
    for( auto it = powerSet.begin(); it != powerSet.end(); ++it ) {
      tmp = *it;
      tmpPowerSet.push_back( tmp );
      tmp.push_back( origSet[ i-1 ] );
      tmpPowerSet.push_back( tmp );
    }
    powerSet = tmpPowerSet;
  }
  
  // output sets
  for( auto it = powerSet.begin(); it != powerSet.end(); ++it ) {
    for( auto it1 = (*it).begin(); it1 != (*it).end(); ++it1 ) {
      cout << *it1 ;
    }
    cout << endl;
  }
}

int main() {
  vector< char > origSet = { 'a', 'b', 'c', 'd' ,'e' };
  getPowerSetV1( origSet );
  getPowerSetV2( origSet );
  return 0;
}


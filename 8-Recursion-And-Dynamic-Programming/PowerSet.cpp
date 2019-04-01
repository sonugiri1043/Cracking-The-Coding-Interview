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

using std::cout;
using std::endl;
using std::vector;

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

int main() {
  vector< char > origSet = { 'a', 'b', 'c', 'd' ,'e' };
  getPowerSetV1( origSet );
  return 0;
}


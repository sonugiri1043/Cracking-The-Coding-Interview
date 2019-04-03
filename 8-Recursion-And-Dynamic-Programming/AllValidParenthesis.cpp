/*
  Parens:
  Implement an algorithm to print all valid ( e.g., properly opened and closed ) combinations
  of n pairs of parentheses.
  EXAMPLE
  Input: 3
  Output: ( ( ( ) ) ), ( ( ) ( ) ), ( ( ) ) ( ), ( ) ( ( ) ), ( ) ( ) ( )
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

void balancedParen( int open, int close, int n, string paren ) { 
  if( close == n ) { // complete balanced parenthesis
    cout<< paren << endl;
    return;
  }
  if( open < n ) {
    balancedParen( open + 1, close, n, paren + "(" );
  } 
  if( open > close ) {
    balancedParen( open, close + 1, n, paren + ")" );
  }
}

int main() {
  int n = 3;
  balancedParen( 0, 0, n, "" );
  return 0;
}

/*
  Boolean Evaluation:
  Given a boolean expression consisting of the symbols 0 (false), 1 (true), & (AND), | (OR), and
  ^ (XOR), and a desired boolean result value result, implement a function to count the number of
  ways of parenthesizing the expression such that it evaluates to result.
  EXAMPLE
  countEval( "1^0|0|1", false ) -> 2
  countEval( "0 & 0 & 0 & 1^1|0", true ) -> 10

  Solution:
  If it's an AND, then both right and left must be true.
  countEval( left & right, true ) = countEval( left, true ) * countEval( right, true )

  If it's an OR, then either the left or the right side must be true or both.
  countEval( left | right, true ) = countEval( left, true ) * countEval( right, false )
                                  + countEval( left, false ) * countEval( right, true )
                                  + countEval( left, true ) * countEval( right, true )

  If it's an XOR, then the left or the right side can be true, but not both.
  countEval( left ^ right, true) = countEval( left, true ) * countEval( right, false )
                                 + countEval( left, false ) * countEval( right, true )

What if we were trying to make the result false instead? We can switch up the logic from above:

  countEval( left & right, false ) = countEval( left, true ) * countEval( right, false )
                                   + countEval( left, false ) * countEval( right, true )
                                   + countEval( left, false ) * countEval( right, false )
  countEval( left | right, false ) = countEval( left, false ) * countEval( right, false )
  countEval( left ^ right, false ) = countEval( left, false ) * countEval( right, false )
                                   + countEval( left, true ) * countEval( right, true )
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool truthValue( string expr ) {
  return expr == "1" ? true : false;
}

int noOfWays( string expr, bool result ) {
  if( expr.length() == 0 ) {
    return 0;
  }
  if( expr.length() == 1 ) {
    return truthValue( expr ) == result ? 1 : 0;
  }

  int noOfWay = 0;
  for( int i = 1; i < expr.length(); i += 2 ) {
    string leftExpr = expr.substr( 0, i );
    string rightExpr = expr.substr( i+1, expr.length() );
    int leftTrue = noOfWays( leftExpr, true );
    int leftFalse = noOfWays( leftExpr, false );
    int rightTrue = noOfWays( rightExpr, true );
    int rightFalse = noOfWays( rightExpr, false );

    if( expr[ i ] == '|' && result ) {
      noOfWay += ( leftTrue * rightFalse ) + ( leftFalse * rightTrue ) +
	( leftTrue * rightTrue );
    }
    if( expr[ i ] == '|' && !result ) {
      noOfWay += leftFalse * rightFalse;
    }
    if( expr[ i ] == '&' && result ) {
      noOfWay += leftTrue & rightTrue; 
    }
    if( expr[ i ] == '&' && !result ) {
      noOfWay += ( leftTrue * rightTrue ) + ( leftFalse * rightTrue ) +
	(leftFalse * rightFalse);
    }
    if( expr[ i ] == '^' && result ) {
      noOfWay += ( leftTrue * rightFalse ) + ( leftFalse * rightTrue );
    }
    if( expr[ i ] == '^' && !result ) {
      noOfWay += ( leftTrue * rightTrue ) + (leftFalse * rightFalse);
    }
  }
  return noOfWay;
} 


int main() {
  string expr1 = "1^0|0|1";
  string expr2 = "0&0&0&1^1|0";
  cout<< noOfWays( expr1, false ) << endl;
  cout<< noOfWays( expr2, true ) << endl;
  return 0;
}

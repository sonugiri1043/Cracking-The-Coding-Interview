/*
  Calculator: Given an arithmetic equation consisting of positive integers, +, -, * and / (no parentheses),
  compute the result.

  EXAMPLE
  Input:
  2*3+5/6*3+15

  Output:
  23.5

  Solution:
  Priority:
  - Division, Multiply
  - Add, Subtract

  Use two stacks: one for numbers and one for operators.
  - Each time we see a number, it gets pushed onto numberStack.
  - Operators get pushed onto operatorStack as long as the operator has higher priority than the
    current top of the stack. If priority(currentOperator) <= priority(operatorStack.top()),
    then we "collapse" the top of the stacks:

    -- Collapsing: pop two elements off numberStack, pop an operator off operatorStack, apply
       the operator, and push the result onto numberStack.

    -- Priority: addition and subtraction have equal priority, which is lower than the priority of multiplication
       and division (also equal priority).

   This collapsing continues until the above inequality is broken, at which point currentOperator is
   pushed onto operatorStack.
   At the very end, we collapse the stack.
 */


// g++ 26-Calculator.cpp --std=c++14

#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::pair;
using std::make_pair;

enum operation {
 op  = 0,
 sub = 1,
 add = 2,
 mul = 3,
 divi = 4,
 num = 5,
};

class Calc {
  stack<double> numberStack;
  stack<int> operatorStack;
  
  int priority( int op ) {
    switch( op ) {
    case sub: return 1;
    case add: return 1;
    case mul: return 2;
    case divi: return 2;
    }
    return 0;
  }

  void collapse() {
    int op = operatorStack.top();
    operatorStack.pop();

    int num1 = numberStack.top();
    numberStack.pop();
    int num2 = numberStack.top();
    numberStack.pop();

    switch( op ) {
    case sub:
      numberStack.push( num2 - num1 );
      return;
    case add:
      numberStack.push( num2 + num1 );
      return;
    case mul:
      numberStack.push( num2 * num1 );
      return;
    case divi:
      numberStack.push( num2/num1 );
      return;
    }
  }
  
  void insertOperatorToStack( int op ) {
    if( operatorStack.empty() ) {
      operatorStack.push( op );
      return;
    }
    if( priority( op ) > priority( operatorStack.top() ) ) {
      operatorStack.push( op );
      return;
    }
    collapse();
    insertOperatorToStack( op );
  }

  double doEvalExpr() {
    while( !operatorStack.empty() ) {
      collapse();
    }
    double res = numberStack.top();
    numberStack.pop();
    return res;
  }

public:
  Calc() {}

  double evalExpr( vector< std::pair< int, int > > expression ) {
    double result;
    for( auto token : expression ) {
      if( token.first == num ) {
	numberStack.push( token.second );
      } else {
	insertOperatorToStack( token.second );
      }
    }
    result = doEvalExpr();
    return result;
  }
};

int main() {
  /*  expression to be evaluated: 2-6-7*8/2+5  */
  vector< std::pair< int, int > > expression = { make_pair(num, 2), make_pair(op, sub),
						 make_pair(num, 6), make_pair(op, sub),
						 make_pair(num, 7), make_pair(op, mul),
						 make_pair(num, 8), make_pair(op, divi),
						 make_pair(num, 2), make_pair(op, add),
						 make_pair(num, 5) };

  Calc calc;
  cout<< calc.evalExpr( expression ) << endl;

  return 0;
}

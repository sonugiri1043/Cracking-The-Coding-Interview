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


#include <iostream>

using std::cout;
using std::endl;

int main() {
  return 0;
}

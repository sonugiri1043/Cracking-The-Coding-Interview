/*
  Write a program to sort a stack such that the smallest items are on the top.
  You can use an additional temporary stack, but you may not copy the elements
  into any other data structure (such as an array). The stack supports the
  following operations: push, pop, peek, and isEmpty.
*/

#include <iostream>
#include <stack>

using namespace std;

void printStack( stack<int> s ) {
  stack<int> tmp;
  while( ! s.empty() ) {
    cout<< s.top() << " ";
    tmp.push( s.top() );
    s.pop();
  }
  cout<< endl;
}

void sortStack( stack<int> &s ) {
  if( s.empty() )
    return;

  // Assume tmpStack is always sorted in reverse order of result
  stack<int> tmpStack;
  tmpStack.push( s.top() );
  s.pop();

  int tmp;
  while( not s.empty() ) {
    // Insert each item from s to tmpStack at appropriate place
    if( tmpStack.top() <= s.top() ) {
      tmpStack.push( s.top() );
      s.pop();
    } else {
      tmp = s.top();
      s.pop();
      // pop item from tmpStack until we hit the rigth spot for tmp      
      while( tmp < tmpStack.top() && ! tmpStack.empty() ) {
	s.push( tmpStack.top() );
	tmpStack.pop();
      }
      // push tmp at right location in tmpStack
      tmpStack.push( tmp );
    }
  }
  // tmpStack is reverse sorted stack
  printStack( tmpStack );
}

int main() {
  stack<int> s1;
  s1.push( 6 );
  s1.push( 8 );
  s1.push( 4 );
  s1.push( 9 );
  s1.push( 2 );

  printStack( s1 );
  sortStack( s1 );
  return 0;
}

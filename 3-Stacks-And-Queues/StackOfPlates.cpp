/*
  Imagine a ( literal ) stack of plates. If the stack gets too high, it might topple.
  Therefore, in real life, we would likely start a new stack when the previous stack
  exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
  SetOfStacks should be composed of several stacks and should create a new stack once
  the previous one exceeds capacity.

  SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
  ( that is, pop() should return the same values as it would if there were just a single
  stack ).

  Sol: Keep a stack of stack, do push and pop in the top stack. delete and add stack
       when threshold is reached.

  FOLLOW UP
  Implement a function popAt( int index ) which performs a pop operation on a specific
  substack.
  sol: Assume all stacks are full except the last one, calulate the index of the stack.
      do a pop and propogate to all other stacks.
*/

#include <iostream>
#include <stack>

using namespace std;

class SetOfStack {
private:
  stack< stack< int > > stackOfStacks;
  int threshold_;
public:
  SetOfStack( int _threshold ) : threshold_( _threshold ) {
    stack< int > s;
    stackOfStacks.push(s);
  }

  void pop() {
    if( not stackOfStacks.top().empty() ) {
      stackOfStacks.top().pop();
    }

    if( stackOfStacks.top().empty() && stackOfStacks.size() > 1 ) {
      stackOfStacks.pop();
    }
  }

  void push( int data ) {
    if( stackOfStacks.top().size() == threshold_ ) {
      stack< int > newStack;
      stackOfStacks.push( newStack );
    }

    if( stackOfStacks.top().size() < threshold_ ) {
      stackOfStacks.top().push( data );
    }
  }

  int top() {
    int data = stackOfStacks.top().top();
    return data;
  }
};

int main() {
  SetOfStack stack( 5 );
  stack.push( 1 );
  stack.push( 2 );
  stack.push( 3 );
  stack.push( 4 );
  stack.push( 5 );
  cout<< " Top " << stack.top() << endl;
  stack.push( 6 );
  cout<< " Top " << stack.top() << endl;
  stack.pop();
  cout<< " Top " << stack.top() << endl;
  return 0;
}

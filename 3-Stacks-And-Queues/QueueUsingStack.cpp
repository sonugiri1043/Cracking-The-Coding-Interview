/*
  Implement a MyQueue class which implements a queue using two stacks.
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> stackNew; // insert element in new after placing all item in new
  stack<int> stackOld; // pop from old after placing all elements in old

public:
  void push( int i ) {
    // insert element in new after placing all item in new stack
    int item;
    while( not stackOld.empty() ) {
      item = stackOld.top();
      stackOld.pop();
      stackNew.push( item );
    }
    stackNew.push( i );
  }

  void pop() {
    int item;
    while( not stackNew.empty() ) {
      item = stackNew.top();
      stackNew.pop();
      stackOld.push( item );
    }
    stackOld.pop();
  }

  int front() {
    int item;
    while( not stackNew.empty() ) {
      item = stackNew.top();
      stackNew.pop();
      stackOld.push( item );
    }
    return stackOld.top();
  }
  
  int size() {
    // size of queue
    return stackNew.size() + stackOld.size();
  }
};

int main() {
  MyQueue queue;
  queue.push( 1 );
  queue.push( 2 );
  cout<< "Front " << queue.front() << endl;
  queue.push( 3 );
  queue.push( 4 );
  cout<< "Front " << queue.front() << endl;
  queue.push( 5 );
  cout<< "Front " << queue.front() << endl;
  queue.pop();
  cout<< "Front " << queue.front() << endl;
  queue.push( 10 );
  cout<< "Front " << queue.front() << endl;
  queue.pop();
  queue.pop();
  queue.pop();
  cout<< "Front " << queue.front() << endl;
  return 0;
}

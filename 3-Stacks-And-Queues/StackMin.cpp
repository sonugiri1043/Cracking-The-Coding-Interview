
/*
  How would you design a stack which, in addition to push and pop, has a function min
  which returns the minimum element? Push, pop and min should all operate in 0(1) time.
 */

#include <iostream>
#include <stack>

using namespace std;

class Node{
private:
  int data_;
  int min_;
public:
  Node( int _data ) : data_( _data ) {}
  int data() { return data_; }
  void dataIs( int _data ) { data_=_data; }
  void minIs( int _min ) { min_ = _min; }
  int min() { return min_; }
};

class StackWithMinOp{  
private:
  stack< Node* > s;
public:
  Node * top() { return s.top(); }
  void pop() { s.pop(); }
  void push( int n ) {
    Node * node = new Node( n );
    int currMin = n;

    if( not s.empty() ) {
      currMin = s.top()->min();
      if( n < currMin ) {
	currMin = n;
      }
    }

    node->minIs( currMin );
    s.push( node );
  }
  int min() { return s.top()->min(); }
};

int main() {
  StackWithMinOp s;
  s.push( 5 );
  cout<< " Min " << s.min() << endl;
  s.push( 6 );
  cout<< " Min " << s.min() << endl;
  s.push( 3 );
  cout<< " Min " << s.min() << endl;
  s.push( 7 );
  cout<< " Min " << s.min() << endl;
  s.pop();
  cout<< " Min " << s.min() << endl;
  s.pop();
  cout<< " Min " << s.min() << endl;
  return 0;
}

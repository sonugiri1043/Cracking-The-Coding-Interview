/*
  Implement a function to check if a linked list is a palindrome.
*/

#include <iostream>
#include <stack>

using namespace std;

class Node {
private:
  int data_;
  Node *next_;
public:
  Node( int _data ) : data_( _data ), next_( NULL ) {}
  ~Node() {  next_ = NULL; }
  Node * next() { return this->next_; }
  int data() { return data_; }
  void dataIs( int _data ) { data_ = _data; }
  void nextIs( Node *node ) { this->next_ = node; }
};

void addFront( Node **head, int data ) {
  Node *newNode = new Node( data );
  newNode->nextIs( *head );
  *head = newNode;
}

void printLL( Node *node ) {
  while( node != NULL ) {
    cout<< node->data() << "->";
    node = node->next();
  }
  cout << endl;
}

bool checkPalindrome( Node * node ) {
  stack< int > s;
  Node *curr = node;
  while( curr != NULL ) {
    s.push( curr->data() );
    curr = curr->next();
  }
  
  curr = node;
  while( s.empty() == false && curr != NULL ) {
    if( s.top() != curr->data() )
      return false;
    s.pop();
    curr = curr->next();
  }

  if( curr == NULL && s.empty() )
    return true;

  return false;
} 

int main() {
  Node *head = NULL;

  // create a LL
  addFront( &head, 8 );
  addFront( &head, 2 );
  addFront( &head, 4 );
  addFront( &head, 6 );
  addFront( &head, 4 );
  addFront( &head, 2 );
  addFront( &head, 8 );
  
  // print Linked List
  printLL( head );
  
  cout<< " Is palindrome: " << checkPalindrome( head ) << endl;
  addFront( &head, 9 );
  cout<< " Is palindrome: " << checkPalindrome( head ) << endl;

  return 0;
}

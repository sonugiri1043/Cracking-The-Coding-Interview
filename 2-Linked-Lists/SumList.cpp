/*
  You have two numbers represented by a linked list, where each node contains a single
  digit. The digits are stored in reverse order, such that the 1 's digit is at the head
  of the list.

  Write a function that adds the two numbers and returns the sum as a linked list.

  EXAMPLE
  Input: ( 7->1->6) + (5->9->2) .That is, 617 + 295.

  Output: 2->1->9. That is, 912.

  FOLLOW UP
  Suppose the digits are stored in forward order. Repeat the above problem.
*/

#include <iostream>

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

void addFront( Node *head, int data ) {
  Node *newNode = new Node( data );
  newNode->nextIs( head->next() );
  head->nextIs( newNode );
}

void printLL( Node *node ) {
  while( node != NULL ) {
    cout<< node->data() << "->";
    node = node->next();
  }
  cout << endl;
}

Node * sumLL( Node *l1, Node *l2 ) {
  Node *l3 = NULL;
  Node *curr = NULL;
  Node *newNode;

  int carry = 0;
  int sum = 0;

  while( l1 != NULL && l2 != NULL ) {

    sum = l1->data() + l2->data() + carry;
    if( sum > 9 )
      carry = 1;
    else
      carry = 0;

    newNode = new Node( sum % 10 );
    if( curr == NULL ) {
      curr = newNode;
      l3 = curr; // result head
    } else {
      curr->nextIs( newNode );
      curr = curr->next();
    }

    l1 = l1->next();
    l2 = l2->next();
  }

  if( l1 == NULL )
    l1 = l2;

  while( l1 != NULL ) {
    sum = l1->data() + carry;
    if( sum > 9 )
      carry = 1;
    else
      carry = 0;

    newNode = new Node( sum % 10 );
    curr->nextIs( newNode );
    curr = curr->next();
    l1 = l1->next();
  }
  return l3;
}

int main() {
  // keep head as a dummy Node
  cout<< "Sum of 2 link list (1 's digit is at the head of the list)" << endl;
  Node *head1 = new Node( -1 );

  // create a LL
  addFront( head1, 8 );
  addFront( head1, 2 );
  addFront( head1, 4 );

  Node *head2 = new Node( -1 );
  addFront( head2, 6 );
  addFront( head2, 0 );
  addFront( head2, 4 );
  addFront( head2, 8 );
  
  // print Linked List
  printLL( head1->next() );
  printLL( head2->next() );
  
  Node *sum = sumLL( head1->next(), head2->next() );
  cout<< "Sum:" << endl;
  printLL( sum );
  return 0;
}

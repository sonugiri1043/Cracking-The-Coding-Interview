/*
  Write code to partition a linked list around a value x, such that all
  nodes less than x come before all nodes greater than or equal to x.
  If x is contained within the list, the values of x only need to be after
  the elements less than x (see below). The partition element x can appear
  anywhere in the "right partition"; it does not need to appear between the
  left and right partitions.

  EXAMPLE
  Input: 3->5->8->5->113->2->1 [ partition = 5 ]
  Output: 3->1->2->113->5->5->8
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

Node* partition( Node *node, int partition ) {
  Node *head = node;
  Node *curr = node;
  Node *prev = NULL;
  while( curr != NULL ) {
    if( curr->data() <= partition &&
	prev != NULL ) {
      // move to front
      prev->nextIs( curr->next() );
      curr->nextIs( head );
      head=curr;
	
      curr=prev; // other wise we keep iterating over it again and again
    }
    prev = curr;
    curr = curr->next();
  }
  return head;
}

int main() {
  // keep head as a dummy Node
  Node *head = new Node( -1 );

  // create a LL
  addFront( head, 8 );
  addFront( head, 12 );
  addFront( head, 14 );
  addFront( head, 16 );
  addFront( head, 10 );
  addFront( head, 14 );
  addFront( head, 18 );
  addFront( head, 10 );
  
  // print Linked List
  printLL( head->next() );

  head = partition( head->next(), 12 );
  
  printLL( head );
  return 0;
}

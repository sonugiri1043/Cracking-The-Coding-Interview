/*
 Implement an algorithm to delete a node in the middle (ie. any node but
 the first and last node, not necessarily the exact middle) of a singly linked
 list, given only access to that node.

 EXAMPLE
 Input: The node c from the linked list a->b->c->d->e->f
 Result: Nothing is returned, but the new linked list looks like a->b->d->e->f
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

void deleteNode( Node *node ) {
  // copy the data from the next node over to the current node,
  // and then to delete the next node.

  Node *curr = node->next();
  node->dataIs( ( node->next() )->data() );
  node->nextIs( curr->next() );
  delete curr;
}

int main() {
  // keep head as a dummy Node
  Node *head = new Node( -1 );

  // create a LL
  addFront( head, 10 );
  addFront( head, 12 );
  addFront( head, 14 );
  addFront( head, 16 );
  addFront( head, 10 );
  addFront( head, 14 );
  addFront( head, 18 );
  addFront( head, 10 );
  
  // print Linked List
  printLL( head->next() );
  deleteNode( ( head->next() )->next() );
  
  printLL( head->next() );

  return 0;
}

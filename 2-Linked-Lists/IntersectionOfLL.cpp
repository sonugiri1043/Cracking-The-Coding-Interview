/*
  Given two (singly) linked lists, determine if the two lists intersect. Return the
  intersecting node. Note that the intersection is defined based on reference, not value.
  That is, if the kth node of the first linked list is the exact same node (by reference)
  as the jth node of the second linked list, then they are intersecting.
*/

#include <iostream>
#include <set>

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

Node * findIntersection( Node *l1, Node *l2 ) {
  set< Node * > nodeSet;
  while( l1 != NULL ) {
    nodeSet.insert( l1 );
    l1 = l1->next();
  }

  while( l2 != NULL ) {
    if( nodeSet.count( l2 ) == 1 )
      return l2;
    l2 = l2->next();
  }
  return NULL;
  // other approach is to traverse each list, if last node is same then they intersect.
  // find the length and then compare node.
}

int main() {
  // create a LL
  Node *head1 = NULL;
  addFront( &head1, 8 );
  addFront( &head1, 2 );
  addFront( &head1, 4 );
  addFront( &head1, 6 );
  addFront( &head1, 4 );
  
  // create another LL
  Node *head2 = NULL;
  addFront( &head2, 8 );
  addFront( &head2, 2 );
  addFront( &head2, 4 );
  addFront( &head2, 6 );
  addFront( &head2, 2 );
  addFront( &head2, 8 );

  // print Linked List
  printLL( head1 );
  printLL( head2 );
  cout<< "Intersection " << findIntersection( head1, head2 ) << endl;
  Node *inter = findIntersection( head1, head1 );
  cout<< "Intersection " << inter << " Data : " << inter->data() <<endl;
  return 0;
}

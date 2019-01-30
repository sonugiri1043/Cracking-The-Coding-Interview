/*
  Given a circular linked list, implement an algorithm that returns the node at the
  beginning of the loop.

  DEFINITION
  Circular linked list: A (corrupt) linked list in which a node's next pointer points
  to an earlier node, so as to make a loop in the linked list.

  EXAMPLE
  Input: A -> B -> C -> D -> E - > C [ the same C as earlier ]
  Output: C
*/

/*
  1. Create two pointers, FastPointer and SlowPointer.
  2. Move FastPointer at a rate of 2 steps and SlowPointer at a rate of 1 step.
  3. When they collide, move SlowPointer to LinkedListHead. Keep FastPointer where it is.
  4. Move SlowPointer and FastPointer at a·rate of one step. Return the new collision point.
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

Node* addFront( Node **head, int data ) {
  Node *newNode = new Node( data );
  newNode->nextIs( *head );
  *head = newNode;
  return newNode;
}

void printLL( Node *node ) {
  while( node != NULL ) {
    cout<< node->data() << "->";
    node = node->next();
  }
  cout << endl;
}

Node *loop( Node *node ) {
  set< Node * > nodeSet;
  while( node != NULL ) {
    if( nodeSet.count( node ) == 0 ) {
      nodeSet.insert( node );
    } else {
      return node;
    }
    node = node->next();
  }
  return NULL;
}

int main() {
  Node *head = NULL;

  // create a LL
  Node *node = addFront( &head, 8 );
  addFront( &head, 2 );
  addFront( &head, 4 );
  
  // print Linked List
  printLL( head );
  cout<< "Loop node " <<  loop( head ) << endl;

  // create loop 
  addFront( &head, 6 );
  addFront( &head, 4 );
  Node *node1 = addFront( &head, 2 );
  addFront( &head, 8 );
  node->nextIs( node1 );

  // print Linked List
  // printLL( head ); commented because of corrupted link-list

  node = loop( head );
  cout<< "Loop node " << node << " data "<< node->data() <<endl;

  return 0;
}

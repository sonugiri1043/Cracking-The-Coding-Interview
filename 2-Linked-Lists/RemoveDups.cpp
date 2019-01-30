/*
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
private:
  int data_;
  Node *next_;
public:
  Node( int _data ) : data_( _data ), next_( NULL ) {}
  ~Node() {
    if( next_ != NULL )
      delete next_;
  }
  Node * next() { return this->next_; }
  int data() { return data_; }
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

void removeDups( Node *node ) {
  unordered_map< int, bool > keyMap;
  Node *currNode = node;
  Node *prev = NULL;
  while( currNode != NULL ) {
    if( keyMap.find( currNode->data() ) == keyMap.end() ) {
      // key not found, insert key in set
      keyMap.insert( make_pair( currNode->data(), true ) );
    } else {
      // key found, remove currNode
      cout<< "Deleting " << currNode->data() << endl;
      prev->nextIs( currNode->next() );
      currNode->nextIs( NULL );
      delete currNode;
      currNode = prev;
    }
    prev = currNode;
    currNode = currNode->next();
  }
}

int main() {
  // keep head as a dummy Node
  Node *head = new Node( -1 );

  // create a LL with some duplicate entries
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

  removeDups( head->next() );
  
  printLL( head->next() );
  return 0;
}

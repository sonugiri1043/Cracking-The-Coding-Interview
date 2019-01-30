/*
  Implement an algorithm to find the kth to last element of a singly linked list.
 */

#include <iostream>

using namespace std;

class Node {
private:
  int data_;
  Node *next_;
public:
  Node( int _data ) : data_( _data ), next_( NULL ) {}
  ~Node() {
    next_ = NULL;
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

Node* kthToLast( Node* head, int k ) {
  int i = k;
  Node *runner1 = head;
  while( i > 0 && runner1 != NULL ) {
    // move runner1 k steps ahead
    runner1 = runner1->next();
    i--;
  }
  Node *runner2 = head;
  while( runner1->next() != NULL ) {
    // when runner 1 reach end, runner 2 would have reached last - kth.
    runner1 = runner1->next();
    runner2 = runner2->next();
  }
  return runner2;
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

  cout<< " 2nd to last " << kthToLast( head->next(), 2 )->data() << endl;
  cout<< " 4nd to last " << kthToLast( head->next(), 4 )->data() << endl;
  return 0;
}

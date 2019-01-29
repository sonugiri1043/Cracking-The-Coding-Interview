/*
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
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
    if( next_ != NULL ) {
      delete next_;
    }
  }

  Node * next() {
    return this->next_;
  }

  int data() {
    return data_;
  }

  void nextIs( Node *node ) {
    this->next_ = node;
  }
};

int main() {
  return 0;
}

/*
  Random Node:
  You are implementing a binary search tree class from scratch, which, in addition
  to insert, find, and delete, has a method getRandomNode() which returns a random
  node from the tree. All nodes should be equally likely to be chosen. Design and 
  implement an algorithm for get RandomNode, and explain how you would implement
  the rest of the methods.
*/

/*
  We must return each node with equal probability.

  Approach 1:
  If N is total no of nodes, probability for root is 1/N. 
  The odds of picking something from the left must have probability LEFT_SIZE * 1/N.
  Likewise, the odds of going right should be RIGHT_SIZE * 1/N. This means that each
  node must know the size of the nodes on the left and the size of the nodes on the
  right. Since we're building this tree class from scratch. It's easy to keep track
  of this size information on inserts and deletes. We can just store a size variable
  in each node. Increment size on inserts and decrement it on deletes.

  Approach 2:
  Random number calls can be expensive. We can reduce the number of random number calls
  substantially.
  The initial random number call indicates which node (i) to return, and then we're locating
  the ith node in an in-order traversal. Subtracting LEFT_SIZE + 1 from i reflects that,
  when we go right, we skip over LEFT_SIZE + 1 nodes in the in-order traversal.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class BstNode {
public:
  int key;
  int size;
  BstNode * left;
  BstNode * right;
  
  BstNode( int _key ) : key( _key ), size( 1 ), left( NULL ), right( NULL ) {} 
};

class Bst {
  BstNode *root;

  BstNode* insertUtil( BstNode *node, int key );
  void printInOrder( BstNode *node );
  BstNode* getIthNode( int i, BstNode* node );

public:
  Bst(): root( NULL ) {}
  void insert( int key );
  BstNode* getRandomNode();
  void print();
};

BstNode* Bst::getIthNode( int i, BstNode *node ) {
  int leftSize = node->left == NULL ? 0: node->left->size;
  if( i <= leftSize) {
    return getIthNode( i, node->left );
  } else if ( i == leftSize + 1 ) {
    return node;
  } else {
    return getIthNode( node->size - i, node->right );
  }
}

BstNode* Bst::getRandomNode() {
  int i = rand() % root->size;
  cout<< "Getting " << i << " th node." << endl;
  return getIthNode( i, root );
}

void Bst::insert( int key ) {
  root = insertUtil( root, key );
}

BstNode* Bst::insertUtil( BstNode *node, int key ) {
  if( node == NULL ) {
    node = new BstNode( key );
    return node;
  }
  if( key <= node->key ) {
    node->left = insertUtil( node->left, key );
  } else {
    node->right = insertUtil( node->right, key );
  }
  node->size++;
  return node;
}

void Bst::print() {
  printInOrder( root );
}

void Bst::printInOrder( BstNode * node ) {
  if( node == NULL ) {
    return;
  }
  printInOrder( node->left);
  cout<< node->key << endl;
  printInOrder( node->right);
}

int main() {
  Bst *bst = new Bst();
  int keys[ 9 ] = { 9, 3, 5, 6, 7, 2, 1, 10, 11 };
  for( int i=0; i < 9; i++ ) {
    bst->insert( keys[i] );
  }
  bst->print();
  for( int i = 0; i < 5; i++ ) {
    cout<< bst->getRandomNode()->key << endl;
  }
  return 0;
}

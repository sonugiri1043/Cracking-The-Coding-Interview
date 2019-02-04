/*
  Write an algorithm to find the "next" node (i.e., in-order successor)
  of a given node in a binary search tree. You may assume that each node
  has a link to its parent.
 */

#include <iostream>

class Node {
public:
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

Node * getMin( Node *node ) {
  if( node == NULL )
    return NULL;

  while( node->left != NULL ) {
    node = node->left;
  }
  return node;
}

Node * successor( Node *node ) {
  if( node == NULL )
    return NULL;

  /* Found right children, return leftmost node of right subtree */
  if( node->right != NULL ) {
    return getMin( node->right );
  } else {
    // Traverse upwards from q until we find a node x that we have
    // not fully traversed
    // i.e. when we move from a left node to its parent
    Node *q = node;
    Node *p = node->parent;
    while( p->left != q && p != NULL ) {
      q = p;
      p = p->parent;
    }
    return p;
  }
}

int main() {
  return 0;
}

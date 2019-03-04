/*
  First Common Ancestor: 
  Design an algorithm and write code to find the first common ancestor of two nodes
  in a binary tree. Avoid storing additional nodes in a data structure.

  NOTE: This is not necessarily a binary search tree.
 */

#include <iostream>

using namespace std;

/*
  Solution 1: Nodes have link to parents
  Let's assume we're looking for the common ancestor of nodes p and q.

  If each node has a link to its parent, we could trace p and q's paths
  up until they intersect. This is essentially the same problem as question
  "find the intersection of two linked lists."  
 */

class NodeWithParentLink {
public:
  int key;
  NodeWithParentLink *parent;
  NodeWithParentLink *left;
  NodeWithParentLink *right;

  NodeWithParentLink( int _key ) : key( _key ), parent( NULL ), left( NULL ), right( NULL ) {} 
};

int getDepth( NodeWithParentLink *p ) {
  int depth = 0;
  while( p->parent != NULL ) {
    p = p->parent;
    depth++;
  }
  return depth;
}

NodeWithParentLink *getCommonAncestor( NodeWithParentLink *p, NodeWithParentLink *q ) {
  // get depth of node p and q
  int pDepth = getDepth( p );
  int qDepth = getDepth( q );

  // advance the pointers to have equal depth
  if( pDepth > qDepth ) {
    for( int i = 0; i < ( pDepth - qDepth ); i++ )
      p = p->parent;
  } else {
    for( int i = 0; i < ( qDepth - pDepth ); i++ )
      q = q->parent; 
  }
  // compare for common ancestor
  while( p != q ) {
    p = p->parent;
    q = q->parent;
  }
  
  if( p == q ) {
    return q;
  }
  return NULL;
}

/*
  Solution 2: Nodes without link to parents  
  Check tree to see if both p and q are in the same side of the tree.
  * If they are on same side then look in node->left sub-tree for common
  ancestor.
  * If they are on different sides then node is the common ancestor.

  This takes O( n ) time, where n is no of nodes in tree.
 */

class Node {
public:
  int key;
  Node *left;
  Node *right;
  
  Node( int _key ) : key( _key ), left( NULL ), right( NULL ) {} 
};

/* Returns True if node is present in tree */
bool covers( Node *node, int p ) {
  if( node == NULL )
    return false;
  if( node->key == p )
    return true;
  return covers( node->left, p ) || covers( node->right, p );
}

Node *commonAncestorHelper( Node *node, int p, int q ) {
  if( node->key == p && node->key == q ) {
    return node;
  }
  bool pInLeft = covers( node->left, p );
  bool qInLeft = covers( node->left, q );
  if( pInLeft && qInLeft ) {
    // if both p and q are present in left sub-tree
    return commonAncestorHelper( node->left, p, q );
  } else if( pInLeft || qInLeft ) {
    // one is present in left and other is present in right
    return node;
  } else {
    // both are present in right sub-tree
    return commonAncestorHelper( node->right, p, q );
  }
}

Node *commonAncestor( Node *node, int p, int q ) {
  if( !covers( node, p ) || ! covers( node, q ) ) {
    // if any of p or q are not present in tree
    return NULL;
  }
  return commonAncestorHelper( node, p, q );
}

int main() {
  return 0;
}

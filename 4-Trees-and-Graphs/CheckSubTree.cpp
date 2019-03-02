/*
  Check Subtree:
  T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an
  algorithm to determine if T2 is a subtree of T1.
  A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree
  of n is identical to T2 . That is, if you cut off the tree at node n, the two trees
  would be identical.

  Approach 1:
  Take pre-order traveral of T1 and T2. In pre-order traversal all null nodes have to
  be marked with X so that trees are unique.
  Now look for T2 pre-order traversal string in T1 pre-order traversal string.

  Approach 2:
  Traverse larger tree, each time you found the root of smaller tree in larger tree.
  Call treeMatch function.
  We do not actually call matchTree on every node in n. Rather, we call it k times,
  where k is the number of occurrences of T2's root in T1. The runtime is closer to O( n + km) .
 */

#include <iostream>

class TreeNode {
public:
  TreeNode( int _key ) : left( NULL ), right( NULL ) {}
  
  int key;
  TreeNode *left;
  TreeNode *right;
};

bool matchTrees( TreeNode *t1, TreeNode *t2 ) {
  if( t1 == NULL && t2 == NULL ) {
    return true;
  } else if( t1 == NULL || t2 == NULL ) {
    return false;
  } else if( t1->key != t2->key ) {
    return false;
  } else {
    return matchTrees( t1->left, t2->left ) && matchTrees( t1->right, t2->right );
  }
}

bool isSubTreeUtil( TreeNode *t1, TreeNode *t2 ) {
  if( t1 == NULL )
    return false;
  if( t1->key == t2->key ) {
    return matchTrees( t1, t2 );
  }
  return isSubTreeUtil( t1->left, t2 ) || isSubTreeUtil( t1->right, t2 );
}

bool isSubTree( TreeNode *t1, TreeNode *t2 ) {
  if( t2 == NULL ) {
    return true; // subtree is empty
  }
  return isSubTreeUtil( t1, t2 );
}

using namespace std;

int main() {
  return 0;
}

/*
  Paths with Sum:
  You are given a binary tree in which each node contains an integer value ( which
  might be positive or negative ). Design an algorithm to count the number of paths
  that sum to a given value. The path does not need to start or end at the root or
  a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 */

#include <iostream>
#include <map>

using namespace std;

class Node {
public:
  int key;
  Node *left;
  Node *right;

  Node( int _key ) {
    key = _key;
    left = NULL;
    right = NULL;
  }
};

void pathWithSum( Node *node, map<Node *, int> sumMap, int tgtSum ) {
  int sum = 0;
  map<Node *, int>::iterator it;
  for( it = sumMap.begin(); it != sumMap.end(); it++ ) {
    // Iterate through all paths and check if sum == tgtSum
    // also update the new sum and add this node as new starting path
    sum = node->key + it->second;
    if( sum == tgtSum ) {
      // target sum is reached, print the path
      cout<< "Start node: " << it->first->key << " end node: " << node->key << endl;
    }
    sumMap[ it->first ] = sum;
    // start a new path starting at this node
    sumMap[ node ] = node->key;
  }
  if( node->left )
    pathWithSum( node->left, sumMap, tgtSum );
  if( node->right )
    pathWithSum( node->right, sumMap, tgtSum );
}

void pathWithSum( Node *root, int sum ) {
  map< Node*, int > sumMap;
  sumMap[ root ] = root->key;

  if( root->key == sum ) {
    cout<< "Sum " << sum << " start node " << root << " end node " << root << endl;
  }

  if( root->left )
    pathWithSum( root->left, sumMap, sum );
  if( root->right )
    pathWithSum( root->right, sumMap, sum );
}

int main() {
  /*  Example Tree

                   10
		 /   \
		5      -3
	      /   \     \
	     3     2     11
	   /  \     \
          3   -2     1

  Solution:
  While traversing the tree we keep track of map<Node*, sum>, which is a
  mapping from starting node and sum from that node till the current node.
  
  At each node, we update this map by adding node->key to sum value and adding
  a new entry for sum starting at this node.

  We also check if the sum has the target, if so, we print the start node and
  this node.
  */

  Node *root = new Node(10);
  root->right = new Node( -3 );
  root->right->right = new Node( 11 );
  
  root->left = new Node( 5 );
  root->left->left = new Node( 3 );
  root->left->right = new Node( 2 );
  root->left->left->left = new Node( 3 );
  root->left->left->right = new Node( -2 );
  root->left->right->right = new Node( 1 );

  pathWithSum( root, 8 );
  return 0;
}

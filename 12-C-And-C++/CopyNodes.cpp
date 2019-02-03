/*
  Write a method that takes a pointer to a Node structure as a parameter
  and returns a complete copy of the passed in data structure. The Node
  data structure contains two pointers to other Nodes.
 */

#include <iostream>
#include <map>

using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
};

map<Node*, Node*> nodeMap;

Node * copyNodes( Node *node ) {
  if( node == NULL )
    return NULL;

  map<Node*, Node*>::iterator it = nodeMap.find( node );
  if( it != nodeMap.end() ) {
    // already visited node
    return it->second;
  }

  Node *copyNode = ( Node * ) malloc( sizeof( Node ) );
  nodeMap[ node ] = copyNode;
  copyNode->key = node->key;

  copyNode->left = copyNodes( node->left );
  copyNode->right = copyNodes( node->right );
  return copyNode;
}

int main() {
  Node *root1;
  // create a graph ...
  Node *root2 = copyNodes( root1 );
  return 0;
}

/*
  Given a binary tree, design an algorithm which creates a linked list
  of all the nodes at each depth ( e.g., if you have a tree with depth D,
  you 'll have D linked lists ).
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node {
public:
  int key;
  Node *left;
  Node *right;
};

/*
  output is a vector of lists.
  each list contain nodes in tree at level i.
 */
vector< list<Node*> > listsOfDepth( Node *node ) {
  vector< list< Node* > > arrayOfLinkList;
  
  list< Node * > curr;
  if( node != NULL ) {
    curr.push_back( node );
  }
  
  while( curr.size() > 0 ) {
    arrayOfLinkList.push_back( curr ); // add nodes at curr level to vector
    
    list< Node * > parents = curr;
    list< Node * >::iterator it;
    curr.clear();
    for( it = parents.begin(); it != parents.end(); it++ ) {
      curr.push_back( *it );
    }
  }
  return arrayOfLinkList;
}

int main() {
  return 0;
}

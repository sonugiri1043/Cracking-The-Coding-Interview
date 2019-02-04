/*
  Given a directed graph, design an algorithm to find out whether there is a
  route between two nodes.
*/

#include <vector> // top store ajcanent nodes of a node 
#include <queue>  // for bfs walk
#include <map>    // to mark visited node, to avoid cycle 

// Node structure
class Node {
public:
  int key;
  vector<Node*> children;
};

bool doesPathExist( Node *start, Node *end ) {
  if( start == end )
    return true;

  map< Node*, bool > nodeMap;
  queue<Node *> nodeQ;
  nodeQ.push( start );

  Node *tmpNode;
  while( !nodeQ.empty() ) {
    tmpNode = nodeQ.top();
    nodeQ.pop();

    vector<Node*>::iterator it;
    for( it = tmpNode->children.begin(): it != tmpNode->children.end(); it++ ) {
      if( nodeMap.find( *it ) == nodeMap.end() ) {
	// node is not visited before
	if( *it == end ) {
	  return true;
	} else {
	  nodeQ.push( *it );
	}
      }
    }
    nodeMap[ tmpNode ] = true;
  }
  return false;
}

/*
  Breadth First Traversal (or Search) for a graph is similar to Breadth First Traversal
  of a tree. The only catch here is, unlike trees, graphs may contain cycles, so we may
  come to the same node again. To avoid processing a node more than once, we use visited
  hash table. For simplicity, it is assumed that all vertices are reachable from the starting
  vertex.
*/


/* To compile use 'g++ bfs.cpp -o <output-file> --std=c++11' */
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::unordered_map;
using std::queue;

class Graph {
public:
  list< int > vertices;
  vector< vector< int > > edges; // adjacency list

  Graph( int noOfVertices ) {
    edges.resize( noOfVertices );
  }

  void bfs( int source ) {
    unordered_map<int, bool> visited( vertices.size() );
    for( int i = 0; i < vertices.size(); i++ ) {
      visited[ i ] = false;
    }

    queue< int > toVisitQueue;
    toVisitQueue.push( source );

    while( !toVisitQueue.empty() ) {
      int vertex = toVisitQueue.front();
      toVisitQueue.pop();
      cout<< ":" << vertex << endl;

      for( auto v : edges[ vertex ] ) {
	if( !visited[ v ] ) {
	  toVisitQueue.push( v );
	  visited[ v ] = true;
	}
      }
    }
  }

};

int main() {
  /*
    Example graph:
           0
	 /  \
	/    \
       /      \
      1        2
      |\       |
      |  \     |
      |    \   |
      |      \ |
      3------- 4
       \      /
        \    /
	  5
   */

  int noOfVertices = 6;
  /* create a graph */
  Graph graph( noOfVertices );
  for( int i = 0; i < noOfVertices; i++ ) {
    // add vertices
    graph.vertices.push_back( i );
  }
  // add edges
  graph.edges[ 0 ].push_back(1);
  graph.edges[ 0 ].push_back(2);  
  graph.edges[ 1 ].push_back(0);
  graph.edges[ 1 ].push_back(3);
  graph.edges[ 1 ].push_back(4);
  graph.edges[ 2 ].push_back(0);
  graph.edges[ 2 ].push_back(4);
  graph.edges[ 3 ].push_back(1);
  graph.edges[ 3 ].push_back(4);
  graph.edges[ 3 ].push_back(5);
  graph.edges[ 4 ].push_back(1);
  graph.edges[ 4 ].push_back(2);
  graph.edges[ 4 ].push_back(3);
  graph.edges[ 4 ].push_back(5);
  graph.edges[ 5 ].push_back(3);
  graph.edges[ 5 ].push_back(5);

  graph.bfs( 0 );
  return 0;
}

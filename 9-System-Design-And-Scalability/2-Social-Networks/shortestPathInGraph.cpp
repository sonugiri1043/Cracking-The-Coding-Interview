/* g++ shortestPathInGraph.cpp --std=c++11 */

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

  vector<int> shortestPath( int source, int dest ) {
    unordered_map<int, bool> visited( vertices.size() );
    for( int i = 0; i < vertices.size(); i++ ) {
      visited[ i ] = false;
    }

    vector<int> path( vertices.size(), -1 );
    queue< int > toVisitQueue;
    toVisitQueue.push( source );
    visited[ source ] = true;

    while( !toVisitQueue.empty() ) {
      int vertex = toVisitQueue.front();
      toVisitQueue.pop();
      cout<< ":" << vertex << endl;

      for( auto v : edges[ vertex ] ) {
	if( !visited[ v ] ) {
	  path[ v ] = vertex;
	  toVisitQueue.push( v );
	  visited[ v ] = true;
	  if( v == dest ) {
	    return path;
	  }
	}
      }
    }
    return path;
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
               |
               |
               |
               |
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
  graph.edges[ 2 ].push_back(0);
  graph.edges[ 2 ].push_back(4);
  graph.edges[ 3 ].push_back(4);
  graph.edges[ 3 ].push_back(5);
  graph.edges[ 4 ].push_back(2);
  graph.edges[ 4 ].push_back(3);
  graph.edges[ 4 ].push_back(5);
  graph.edges[ 5 ].push_back(3);
  graph.edges[ 5 ].push_back(5);

  int src = 0;
  int dest = 3;
  vector<int> path = graph.shortestPath( 0, 3 );

  // print path
  int prev = 3;
  while( prev != src ) {
    cout<< prev << "<-";
    prev = path[ prev ];
  }
  cout<< src << endl;

  return 0;
}

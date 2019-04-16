/*
  How does Bi-directional BFS work?
  Simultaneously run two BFS's from both source and target vertices, terminating once
  a vertex common to both runs is discovered. This vertex will be halfway between the
  source and the target.

  Why is it better than BFS?
  Bi-directional BFS will yield much better results than simple BFS in most cases.
  Assume the distance between source and target is k, and the branching factor is B
  (every vertex has on average B edges).

  BFS will traverse 1 + B + B^2 + ... + B^k vertices.
  Bi-directional BFS will traverse 2 + 2B^2 + ... + 2B^(k/2) vertices.

  For large B and k, the second is obviously much faster the the first.
*/

/*
   g++ BidirectionalBFS.cpp --std=c++14
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::unordered_map;
using std::queue;

class Graph {
public:
  list< string > vertices;
  unordered_map< string, vector<string> > neighbours; // adjacency list

  void biDirectionalBFS( string src, string dst ) {
    queue< string > toVisitFromSrc;
    unordered_map< string, string > visitedFromSrc;
    queue< string > toVisitFromDst;
    unordered_map< string, string > visitedFromDst;

    toVisitFromSrc.push( src );
    visitedFromSrc[ src ] = "";
    toVisitFromDst.push( dst );
    visitedFromDst[ dst ] = "";
    while( !toVisitFromSrc.empty() && !toVisitFromDst.empty() ) {
      string collission;
      collission = levelTravel( toVisitFromSrc, visitedFromSrc, visitedFromDst );
      if( collission != "" ) {
	cout<< "Collission occured at vertex: " << collission << endl;
	// build path from collission vertex to src and dst
	break;
      }
      collission = levelTravel( toVisitFromDst, visitedFromDst, visitedFromSrc );
      if( collission != "" ) {
	cout<< "Collission occured at vertex: "<< collission << endl;
	// build path from collission vertex to src and dst
	break;
      }
    }
  }

  /* Return the vertex if collision occured i.e. bfs from src and dst met */
  string levelTravel( queue< string > &toVisit,
		      unordered_map< string, string > &visitedPrimary,
		      unordered_map< string, string > &visitedSec ) {
    int size = toVisit.size();
    for( int i = 0; i < size; ++i ) {
      string vertex = toVisit.front();
      toVisit.pop();
      for( auto v : neighbours[ vertex ] ) {
	if( visitedPrimary.find( v ) == visitedPrimary.end() ) {
	  toVisit.push( v );
	  visitedPrimary[ v ] = vertex;
	}
	if( visitedSec.find( v ) != visitedSec.end() ) {
	  return v; // collission vertex, present in both visited hashmaps
	}
      }
    }
    return "";
  }

};

Graph& createExampleGraph() {
  /* Create graph to test bi-directional BFS */
  Graph *graph = new Graph();
  vector< string > V = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
			 "n", "o" };
  for( auto v : V ) {
    graph->vertices.push_back( v );
  }
  graph->neighbours[ "a" ] = { "e" };
  graph->neighbours[ "b" ] = { "e" };
  graph->neighbours[ "e" ] = { "f" };
  graph->neighbours[ "d" ] = { "f" };
  graph->neighbours[ "e" ] = { "a", "b", "g" };
  graph->neighbours[ "f" ] = { "e", "d", "g" };
  graph->neighbours[ "g" ] = { "e", "f", "h" };
  graph->neighbours[ "h" ] = { "g", "i" };
  graph->neighbours[ "i" ] = { "h", "j", "k" };
  graph->neighbours[ "j" ] = { "i", "l", "m" };
  graph->neighbours[ "k" ] = { "i", "n", "o" };
  graph->neighbours[ "l" ] = { "j" };
  graph->neighbours[ "m" ] = { "j" };
  graph->neighbours[ "n" ] = { "k" };
  graph->neighbours[ "o" ] = { "k" };
  return *graph;
};

int main() {
  cout<< "Bi-directional BFS to find shortest distance between two nodes in an "
      << "un-weighted graph" << endl;
  Graph g = createExampleGraph();
  g.biDirectionalBFS( "a", "m" );
  return 0;
}

/*
  Build Order:

  You are given a list of packages and a list of dependencie ( which is a list of pairs of packages,
  where the second project is dependent on the first package ). All of a package's dependencies must
  be built before the package is. Find a build order that will allow the packagess to be built.  If
  there is no valid build order, return an error.

  EXAMPLE
  Input:
  Projects: a, b, c, d, e, f
  Dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)

  Output: f, e, a, b, d, c
 */

/*
  Approach:
  1. We first added the nodes with no incoming edges. If the set of package can be built, there must
  be some "first" package, and that package can't have any dependencies. If a package has no dependencies
  (incoming edges), then we certainly can't break anything by building it first.
  2. We removed all outgoing edges from these roots. This is reasonable. Once those root package were
  built, it doesn't matter if another package depends on them.
  3. After that, we found the nodes that now have no incoming edges. Using the same logic from steps 1
  and 2, it's okay if we build these. Now we just repeat the same steps: find the nodes with no dependencies,
  add them to the build order, remove their outgoing edges, and repeat.
  4. What if there are nodes remaining, but all have dependencies (incoming edges)? This means there's no
  way to build the system. We should return an error.
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Represents a Node
class Package {
public:
  Package( string pkgName ) : name( pkgName ), dependencies( 0 ) { }
  string getName() { return name;  }
  void decDependency() { dependencies--; }
  void incDependency() { dependencies++; }
  int getNumDependency() { return dependencies; }
  vector< Package* >  getChildren() { return children; }
  void addChild( Package *package ) {
    if( childMap.count( package->getName() ) == 0 ) {
      children.push_back( package );
      package->incDependency();
      childMap[ package->getName() ] = package;
    }
  }
private:
  string name;
  int dependencies;
  vector< Package * > children;
  map< string, Package * > childMap;
};

// Represents a directed graph of packages
class Graph {
public:
  Package *getOrCreateNode( string packageName ) {
    createNode( packageName );
    return nodeMap[ packageName ];
  }
  void createNode( string packageName ) {
    if( nodeMap.count( packageName ) == 0 ) {
      Package *pkg = new Package( packageName );
      nodeMap[ packageName ] = pkg;
      nodes.push_back( pkg );
    }
  }
  void addEdge( string startName, string endName ) {
    Package *start = getOrCreateNode( startName );
    Package *end = getOrCreateNode( endName );
    start->addChild( end );
  }
  vector< Package * > getNodes() { return nodes; }
private:
  vector< Package * > nodes;
  map< string, Package * > nodeMap;
};

Graph * buildGraph( string packages[], int nodes,
		    string dependency[][2], int edges ) {
  /* Build the graph, adding the edge ( a, b ) if b is dependent on a.
     This indicates that b depends on a and a must be built before b. */
  Graph *graph = new Graph();
  for( int i = 0; i < nodes; i++ ) {
    graph->createNode( packages[ i ] );
  }
  for( int i = 0; i < edges; i++ ) {
    graph->addEdge( dependency[ i ][ 0 ], dependency[ i ][ 1 ]  );
  }
  return graph;
}

/* A helper function to insert packages with no dependencies in order array at offset. */
int addNonDependentNodes( vector<Package *> &order, vector<Package*> packages,
			  int offset ) {
  for( vector<Package*>::iterator it = packages.begin(); it != packages.end(); it++ ) {
    if( (*it)->getNumDependency() == 0 ) {
      order.push_back( *it );
      offset++;
    }
  }
  return offset;
}

vector< Package * > orderProjects( vector< Package * > packages ) {
  vector< Package * > emptyVector; // to be returned when no order is possible
  vector< Package * > order;
  int index = addNonDependentNodes( order, packages, 0 );
  int toBeProcessed = 0;
  while( toBeProcessed < packages.size() ) {
    if( order.size() <= toBeProcessed ) {
      return emptyVector;
    } else {
      Package *pkg = order[ toBeProcessed ];
      // Remove pkg from dependency of all children.
      vector<Package *> children = pkg->getChildren();
      for( vector<Package *>::iterator it = children.begin(); it != children.end(); it++ ) {
	(*it)->decDependency();
      }
      // Add new non-dependent nodes in un-processed order vector
      index = addNonDependentNodes( order, children, index );
    }
    toBeProcessed++;
  }
  return order;
}

int main () {
  string packages[] = { "a", "b", "c", "d", "e", "f" };
  string dependency[][2] = { { "a", "d" },
			     { "f", "b" },
			     { "b", "d" },
			     { "f", "a" },
			     { "d", "c" } };
  int nodes = 6;
  int edges = 5;

  Graph *graph = buildGraph( packages, nodes, dependency, edges );
  vector< Package * > packageOrder = orderProjects( graph->getNodes() );

  // output
  cout<< "Packages:" << endl;
  for( int i=0; i<nodes; i++ ) {
    cout<< packages[i] << " ";
  }
  cout<< endl;
  cout<< "Dependency:" << endl;
  for( int i=0; i<edges; i++ ) {
    cout<< "(" << dependency[i][0] << " ," << dependency[i][1] << "), ";
  }
  cout<< endl;
  cout<< "Build order:" << endl;
  for( int i=0; i < packageOrder.size(); i++ ) {
    cout<< packageOrder[ i ]->getName() << ", ";
  }
  cout<< endl;

  return 0;
}

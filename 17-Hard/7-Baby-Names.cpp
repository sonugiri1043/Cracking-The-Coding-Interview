/*
  Baby Names:
  Each year, the government releases a list of the 10,000 most common baby names
  and their frequencies (the number of babies with that name). The only problem with this is that
  some names have multiple spellings. For example, "John" and "Jon" are essentially the same name
  but would be listed separately in the list. Given two lists, one of names/frequencies and the other
  of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each
  name. Note that if John and Jon are synonyms, and Jon and Johnny are synonyms, then John and
  Johnny are synonyms. (It is both transitive and symmetric.) In the final list, any name can be used
  as the "real" name.
  EXAMPLE
  Input:
  Names: John (15), Jon (12), Chris (13), Kris (4), Christopher (19)
  Synonyms: (Jon, John), (John, Johnny), (Chris, Kris), (Chris, Christopher)
  Output: John (27), Kris (36)
 */

// g++ 7-Baby-Names.cpp --std=c++14

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::set;
using std::stack;

struct Node {
  string name;
  int freq;
  set<string> neighbour;
  
  Node( string name_, int freq_ ) : name( name_ ), freq( freq_ ) {}
};

class Graph {
  unordered_map<string, Node *> nodes;
  
  void addNodes( const unordered_map<string, int> nameToFreqMap ) {
    for( auto itr = nameToFreqMap.begin(); itr != nameToFreqMap.end(); itr++ ) {
      nodes.insert( std::make_pair( (*itr).first,
				    new Node( (*itr).first, (*itr).second ) ) );
    }
  }
  
  void addEdges( const unordered_map<string, string> synonymMap ) {
    for( auto it = synonymMap.begin(); it != synonymMap.end(); it++ ) {
      string a = (*it).first;
      string b = (*it).second;
      // add b to a neighbour
      nodes[a]->neighbour.insert( b );
      // add a to b neighbour
      nodes[b]->neighbour.insert( a );
    }
  }
  
  void dfs( string node, unordered_map< string, bool> &visited, int &sum ) {
    stack< string > s;
    s.push( node );
    visited[ node ] = true;
    sum += nodes[ node ]->freq;
    while( !s.empty() ) {
      string tmp = s.top();
      s.pop();
      for( auto n : nodes[ tmp ]->neighbour ) {
	// if not visited put in stack
	if( visited.find( n ) == visited.end() ) {
	  visited[ n ] = true;
	  sum += nodes[ n ]->freq;
	  s.push( n );
	}
      }
    }
}

public:
  void createGraph( const unordered_map<string, int> nameToFreqMap,
		    const unordered_map<string, string> synonymMap ) {
    this->addNodes( nameToFreqMap );
    this->addEdges( synonymMap );
  }

  auto getCount() {
    unordered_map< string, bool> visited;
    unordered_map< string, int> nameToFreq;
    for( auto it = nodes.begin(); it != nodes.end(); it++ ) {
      if( visited.find( (*it).first ) == visited.end() ) {
	// if the node has not been visited get the sum of all the nodes in that
	// connected component
	int sum = 0;
	this->dfs( (*it).first, visited, sum );
	nameToFreq[ (*it).first ] = sum;
      }
    }
    return nameToFreq;
  }

};

int main() {
  unordered_map<string, int> nameToFreqMap = { {"john", 10}, {"jon", 3}, {"davis", 2},
					       {"kari", 3}, {"johnny", 11}, { "carlton", 8},
					       {"carleton", 2}, {"jonathan", 9}, {"carrie", 5} };
  unordered_map<string, string> synonymMap = { {"jonathan", "john"}, {"jon","johnny"},
					       {"johnny", "john"}, {"kari","carrie"},
					       {"carleton", "carlton"} };

  Graph g;
  g.createGraph( nameToFreqMap, synonymMap );

  unordered_map< string, int> nameToFreq = g.getCount();
  for( auto it = nameToFreq.begin(); it != nameToFreq.end(); ++it ) {
    cout<< "Name: " << (*it).first << " Count: " << (*it).second << endl;
  } 
  return 0;
}

/* 
  Multi Search:
  Given a string b and an array of smaller strings T, design a method to search b for
  each small string in T.
  
  Example:
  T = { "is", "ppi", "hi", "sis", "i", "ssippi" }
  b = "mississippi"

  Solution 1:
  Just search through the bigger string for each instance of the smaller string.

  Solution 2:
  We should think about how we can tackle all the elements in T at once, or somehow re-use work.
  One way is to create a trie-like data structure using each suffix in the bigger string.
  For the string bibs, the suffix list would be: bibs, ibs, bs, s.
 */

// g++ 17-Multi-Search.cpp --std=c++11

#include <iostream>
#include <unordered_map>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::unordered_map;
using std::list;
using std::string;

class TrieNode {
public:
  unordered_map< char, TrieNode* > children;
  list<int> suffixStartPos; // position in original string where suffix starts
};

class Trie {
  TrieNode *root;
public:
  Trie() {
    root = new TrieNode();
  }

  void insert( string suffix, int pos );
  list<int> search( string s );
};

void Trie::insert( string suffix, int pos ) {
  TrieNode *node = root;
  for( auto c : suffix ) {
    if( node->children.find( c ) == node->children.end() ) {
      node->children.insert( std::make_pair( c, new TrieNode() ) );
    }
    node = node->children[ c ];
    // along the path put position where it start in original string
    node->suffixStartPos.push_back( pos );
  }
}

list<int> Trie::search( string s ) {
  TrieNode *node = root;
  list< int > searchPos;
  for( auto c : s ) {
    if( node->children.find( c ) != node->children.end() ) {
      node = node->children[c];
    } else {
      return searchPos;
    }
  }
  return node->suffixStartPos;
}

int main() {
  Trie trie;
  string input = "mississippi";
  for( size_t i = 0; i < input.length(); ++i ) {
    trie.insert( input.substr( i ), i );
  }
  list< int > searchPos;
  searchPos = trie.search( "is" );
  cout<< searchPos.size() << endl;
  searchPos = trie.search( "ppi" );
  cout<< searchPos.size() << endl;
  searchPos = trie.search( "hi" );
  cout<< searchPos.size() << endl;
  return 0;
}

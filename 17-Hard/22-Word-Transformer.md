## Word Transformer
   Given two words of equal length that are in a dictionary, write a method to transform one
   word into another word by changing only one letter at a time. The new word you get in each
   step must be in the dictionary.

``` bash
    EXAMPLE
      Input: DAMP, LIKE
      Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE
```

## Solution

### Brute Force
This is essentially a breadth-first search where there is an "edge" between two words if they are only one edit
apart.

```c++
// g++ filename.cpp --std=c++11
#include <unordered_map>
#include <list>
#include <string>

using std::unordered_map;
using std::list;
using std::string;

class WordTransform {
  unordered_map<string, bool> dictionary;
  unordered_map<string, string> visited; // child <- parent pair, gives us path
  string letters;

  /* returns list of all words one edit distance at away from "input" */
  void getWordsOneEditAway( string input, list<string> &words ) {
    int size = input.length();
    string word;
    for( int pos = 0; pos < input.length(); ++pos ) {
      for( char c = 'a'; c <= 'z'; c++ ) {
        word = input.substr( 0, pos ) + c + input.substr( pos + 1 );
        if( dictionary.find( word ) != dictionary.end() ||
            visited.find( word ) != visited.end() ) {
          words.push_back( word );
	  visited.insert( std::make_pair( word, input ) );
        }
      }
    }
  }

public:
  bool wordReachable( string start, string end ) {
    if( start == end ) {
      return true;
    }

    visited.insert( std::make_pair( start, "" ) );
    string word;
    int noOfHops = 0;
    list< string > words;
    getWordsOneEditAway( start, words );
    while( !words.empty() ) {
      list< string > nextLevelWords;
      while( !words.empty() ) {
        word = words.front();
        words.pop_front();
        if( word == end ) {
          return true;
        }
	getWordsOneEditAway( word, nextLevelWords );
      }
      words = nextLevelWords;
      nextLevelWords.clear();
      noOfHops += 1;
    }
    return false;
  }
  // to get the path traverse the visited array from 'end'
};
```

### Optimal Solution
  Imagine that the path between two nodes has length 4. With breadth-first search, we will visit about 26^4
  nodes to find them. Breadth-first search spans out very quickly.
  Instead, what if we searched out from the source and destination nodes simultaneously? In this case, the
  breadth-first searches would collide after each had done about two levels each.
  - Nodes travelled to from source: 26^2
  - Nodes travelled to from destination: 26^2
  - Total nodes: 26^2 + 26^2

  This is much better than the traditional breadth-first search.

```c++

#include <unordered_map>
#include <list>
#include <string>

using std::unordered_map;
using std::list;
using std::string;

class WordTransform {
  unordered_map<string, bool > dictionary;

  /* Performs one level of breadth-first traversal*/
  bool bfsOnWords( list<string> level, unordered_map< string, string > &startVisited,
                   unordered_map< string, string > &endVisited ) {
    string word;
    list<string> level1;
    while( !level.empty() ) {
      word = level.front();
      level.pop_front();

      // Get all words one edit away from word and add to level1 list
      // if it is in dictionary and has not been visited before
      for( int pos = 0; pos < word.length(); ++pos ) {
        string nextword;
        for( char c = 'a'; c <= 'z'; c++ ) {
          nextword = word.substr( 0, pos ) + c + word.substr( pos + 1 );
          if( dictionary.find( word ) != dictionary.end() &&
	      startVisited.find( word ) == startVisited.end() ) {
            level1.push_back( word );
            startVisited.insert( std::make_pair( nextword, word ) );
          } else if( endVisited.find( word ) != endVisited.end() ) {
	    // Both BFS from start and end has visited this
            // we have found a route, return.
            return true;
          }
        }
      }

    }
    level = level1;
    level1.clear();
    return false;
  }

  bool reachable( string start, string end ) {
    // visited hashmap for start and end
    unordered_map< string, string > startVisited;
    unordered_map< string, string > endVisited;
    startVisited.insert( std::make_pair( start, "" ) );
    endVisited.insert( std::make_pair( end, "" ) );

    // list for start and end to be used in BFS
    list< string > startLevel;
    list< string > endLevel;
    startLevel.push_back( start );
    endLevel.push_back( end );

    bool foundStart = false;
    bool foundEnd = false;
    while( !startLevel.empty() && !endLevel.empty() ) {
      foundStart = bfsOnWords( startLevel, startVisited, endVisited );
      if( foundStart )
        break;
      foundEnd = bfsOnWords( endLevel, endVisited, startVisited );
      if( foundEnd )
        break;
    }
    // TODO: Get the path from visited array
    return foundEnd || foundStart;
  }
};
```
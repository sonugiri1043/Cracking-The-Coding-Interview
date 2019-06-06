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


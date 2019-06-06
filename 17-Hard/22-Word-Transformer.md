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
  unordered_map<string, bool> visited;
  string letters;

  /* returns list of all words one edit distance at away from "input" */
  void getWordsOneEditAway( string input, list<string> &words ) {
    int size = input.length();
    string word;
    for( int pos = 0; pos < input.length(); ++pos ) {
      for( char c = 'a'; c <= 'z'; c++ ) {
        word = input.substr( 0, pos ) + c + input.substr( pos + 1 );
        if( dictionary.find( word ) != dictionary.end() ) {
          words.push_back( word );
        }
      }
    }
  }

public:
  bool wordReachable( string start, string end ) {
    if( start == end ) {
      return true;
    }
    string word;
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
	if( visited.find( word ) != visited.end() ) {
           // we have already visited this word
	   continue;
        }
        getWordsOneEditAway( word, nextLevelWords );
      }
      words = nextLevelWords;
      nextLevelWords.clear();
    }
    return false;
  }
};
```


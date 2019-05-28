/*
  T9:
  On old cell phones, users typed on a numeric keypad and the phone would provide a list of words
  that matched these numbers. Each digit mapped to a set of 0 - 4 letters. Implement an algorithm
  to return a list of matching words, given a sequence of digits. You are provided a list of valid words
  (provided in whatever data structure you'd like). The mapping is shown in the diagram below:
*/

// g++ 20-T9.cpp --std=c++14

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::queue;

void getAllPossibleWords( vector<string> letterMap, string input ) {
  queue<string> words;
  words.push( "" );

  for( auto i : input ) {
    string map = letterMap[ i - '0' ];

    int size = words.size();
    for( int j = 0; j < size; ++j ) {
      string tmp = words.front();
      words.pop();
      for( auto letter : map ) {
	words.push( tmp + letter );
      }
    }
  }

  while( !words.empty() ) {
    cout<< words.front() << endl;
    words.pop();
  }
}

int main() {
  vector<string> letterMap = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
  string input = "8733";
  getAllPossibleWords( letterMap, input );
  return 0;
}

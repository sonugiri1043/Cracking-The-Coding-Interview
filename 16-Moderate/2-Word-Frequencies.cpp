/* Word Frequencies:
   Design a method to find the frequency of occurrences of any given word in a
   book. What if we were running this algorithm multiple times? */

// Compile using: g++ 2-Word-Frequencies.cpp --std=c++14

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::map;

/*If the fequencies have to searched for only one time.*/
int wordFrequency( string word, const vector<string> book ) {
  int freq = 0;
  for( auto s : book ) {
    std::transform( s.begin(), s.end(), s.begin(), tolower );
    if( s == word ) {
      ++freq;
    }
  }
  return freq;
}


/* Repetitive Queries*/
map< string, int > createWordFreqTable( const vector<string> book ) {
  map< string, int> wordFreqTable;
  for( auto s : book ) {
    std::transform( s.begin(), s.end(), s.begin(), tolower );
    if ( wordFreqTable.find( s ) != wordFreqTable.end() ) {
      ++wordFreqTable[s];
    } else {
      wordFreqTable[s] = 1;
    }
  }
  return wordFreqTable;
}

int getFreqency( map< string, int> &wordFreqTable, string word ) {
  if( word == "" )
    return -1;

  std::transform( word.begin(), word.end(), word.begin(), tolower );
  int count = 0;
  if( wordFreqTable.find( word ) != wordFreqTable.end() ) {
    count = wordFreqTable[ word ];
  }
  return count;
}

int main() {
  vector< string> s = { "Convert", "to", "Lower", "TO" };
  cout << wordFrequency( "to", s ) << endl;
  map< string, int > wordFreqTable = createWordFreqTable( s );
  cout<< getFreqency( wordFreqTable, "to" ) << endl;
  return 0;
}

/*
  Diving Board: You are building a diving board by placing a bunch of planks of wood end-to-end.
  There are two types of planks, one of length shorter and one of length longer. You must use
  exactly K planks of wood. Write a method to generate all possible lengths for the diving board.
 */

#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

set<int> allPossibleDivingBoardLen( int longerLen, int shorterLen, int k ) {
  int len = 0;
  set< int > allLengths;
  for( int i = 0; i < k; ++i ) {
    len = i*shorterLen + ( k - i )* longerLen;
    allLengths.insert( len );
  }
  return allLengths;
}

int main() {
  int lenOfLongerPlank = 8;
  int lenOfShorterPlank = 3;
  int k = 25;
  allPossibleDivingBoardLen( lenOfLongerPlank, lenOfShorterPlank, k );
  return 0;
}

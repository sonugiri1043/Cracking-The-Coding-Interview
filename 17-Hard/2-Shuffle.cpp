/*
  Shuffle:
  Write a method to shuffle a deck of cards. It must be a perfect shuffle-in other words, each
  of the 52! permutations of the deck has to be equally likely. Assume that you are given a random
  number generator which is perfect.

  Solution:
  This is a well-known interview question, and a well known alogorithm.
  Let's imagine our n-element array. Suppose it looks like this:
  [1] [2] [3] [4] [5]
  
  Using BaseCase and Build approach, we can ask this question: suppose we had a method shuffle(...)
  that worked on n-1 elements. Could we use this to shuffle n elements?

  We would first shuffle the first n-1 elements. Then, we would take the nth element and randomly swap
  it with an element in the array.
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;

void shuffle( vector<int> &cards ) {
  int randIndex;
  int size = cards.size();
  int tmp;
  for( int i=0; i < size; ++i ) {
    randIndex = rand() % size - i; // 0 to size - i - 1
    // swap index randIndex and index 'size - 1 - i'
    tmp = cards[ randIndex ];
    cards[ randIndex ] = cards[ i ];
    cards[ i ] = tmp;
  }
}

int main() {
  return 0;
}

/*
  Master Mind:
  The Game of Master Mind is played as follows:
  The computer has four slots, and each slot will contain a ball that is red (R), yellow (Y), green (G) or
  blue (B). For example, the computer might have RGGB (Slot #1 is red, Slots #2 and #3 are green, Slot
  #4 is blue).

  You, the user, are trying to guess the solution. You might, for example, guess YRGB.
  When you guess the correct color for the correct slot, you get a "hit:' If you guess a color that exists
  but is in the wrong slot, you get a "pseudo-hit:' Note that a slot that is a hit can never count as a
  pseudo-hit.

  For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudohit.
  Write a method that, given a guess and a solution, returns the number of hits and pseudo-hits.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

void score( string actual, string guess ) {
  /*
    We implement this code by first creating a frequency map which stores
    how many times each character occurs in solution, excluding times when
    the slot is a "hit". Then, we iterate through guess to count the number
    of pseudo-hits.
  */
  
  int hit=0;
  int pseudoHit=0;

  unordered_map<char, int> count;
  count.insert( std::make_pair( 'R', 0 ) );
  count.insert( std::make_pair( 'G', 0 ) );
  count.insert( std::make_pair( 'B', 0 ) );
  count.insert( std::make_pair( 'Y', 0 ) );
  
  for( int i = 0; i < actual.length(); ++i ) {
    if( actual[ i ] == guess[ i ] ) {
      ++hit;
    } else {
      count[ actual[ i ] ] = count[ actual[ i ] ] +  1;
    }
  }

  for( int i = 0; i < guess.length(); ++i ) {
    if( count[ guess[i] ] > 0 ) {
      count[ guess[i] ] = count[ actual[ i ] ] - 1;
      pseudoHit++;
    }
  }

  cout<< "Hit:" << hit << " Pseudo Hit:"<< pseudoHit <<endl;
}

int main() {
  string actual = "RGBY";
  string guess1 = "GGRR";
  string guess2 = "RGGB";
  score( actual, guess1 );
  score( actual, guess2 );
  return 0;
}

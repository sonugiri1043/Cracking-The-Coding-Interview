/*
  Langton's Ant:
  An ant is sitting on an infinite grid of white and black squares. It initially faces right.
  At each step, it does the following:
  (1) At a white square, flip the color of the square, turn 90 degrees right (clockwise), and move forward
  one unit.
  (2) At a black square, flip the color of the square, turn 90 degrees left (counter-clockwise), and move
  forward one unit.
  Write a program to simulate the first K moves that the ant makes and print the final board as a grid.
  Note that you are not provided with the data structure to represent the grid. This is something you
  must design yourself. The only input to your method is K. You should print the final grid and return
  nothing. The method signature might be something like void printKMoves (int K) .
 */

#include <iostream>
#include <set>

using std::set;

class Board {
  // If a position is in the set, then the square is
  // white. Otherwise, it is black.
  set< std::pair<int, int> > whites;
  std::pair<int, int> topLeft;
  std::pair<int, int> bottomRight;

public:
  Board() {
    topLeft = std::make_pair( 0, 0 );
    bottomRight = std::make_pair( 0, 0);
  }

  bool isWhite( int x ,int y ) {
  }
};

int main() {
  // TODO:
  return 0;
}

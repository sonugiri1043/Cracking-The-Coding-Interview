/*
  Paint Fill:
  Implement the "paint fill" function that one might see on many image editing programs.
  That is, given a screen (represented by a two-dimensional array of colors), a point,
  and a new color, fill in the surrounding area until the color changes from the original
  color.
 */

#include <iostream>

enum Color { Red,
	     Green,
	     Blue };

void paintFill( int row, int col, Color **arr, int numRow, int numCol,
		Color toFill, Color origCol ) {
  if( ( row < 0  || col < 0 ) || ( row >= numRow || col >= numCol ) ) {
      return;
  } else if( arr[ row ][ col ] == origCol ) {
    arr[ row ][ col ] = toFill;
    paintFill( row + 1, col, arr, numRow, numCol, toFill, origCol );
    paintFill( row, col + 1, arr, numRow, numCol, toFill, origCol );
    paintFill( row - 1, col, arr, numRow, numCol, toFill, origCol );
    paintFill( row, col - 1, arr, numRow, numCol, toFill, origCol );
  }
}

int main() {
  return 0;
}

/* Draw Line:
   A monochrome screen is stored as a single array of bytes, allowing eight consecutive
   pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (
   that is, no byte will be split across rows ). The height of the screen, ofcourse, can
   be derived from the length of the array and the width. Implement a function that draws
   a horizontal line from ( x1, y ) to ( x2, y ).
   The method signature should look something like:
 
   drawLine( byte[] screen, int width, int x1, int x2 , int y )
 */

#include <iostream>
using std::cout;
using std::endl;

void drawLine( int (&screen)[], int width, int x1, int x2, int y ) {
  int start = x1/8;
  int startOffset = x1 % 8;
  int end = x2/8;
  int endOffset = x1 % 8;

  if( start == end ) {
    // set bit from startOffset to endOffset
  } else {
    // set bytes from start + 1 to end - 1
    for( int i = start + 1; i < end -1; i++ )
      screen[ i ] = 0xff;
    // handle start byte, set bits from startOffset to 7th bit
    int mask = 0xff;
    while( startOffset ) {
      mask = mask << 1;
      startOffset--;
    }
    screen[ start ] = mask;
    // handle end byte, set bits from 0th to endOffset
    mask = 0xff;
    while( endOffset ) {
      mask = mask >> 1;
    }
    screen[ end ] = mask;
  }
}

int main() {
  
  return 0;
}

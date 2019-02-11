/* Pairwise Swap:
   Write a program to swap odd and even bits in an integer with as few instructions as
   possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
*/

#include <iostream>
using std::cout;
using std::endl;

int pairwsiseSwap( int n ) {
  int evenMask = 0x55555555; // 0101 0101 ...
  int oddMask =  0xaaaaaaaa; // 1010 1010 ...
  
  return ( evenMask & n >>> 1 ) | ( oddMask & n << 1 );
}

int main() {
  return 0;
}

/* Next Number:
   Given a positive integer, print the next smallest and the next largest number that
   have the same number of 1 bits in their binary representation.
 */

#include <iostream>
using std::cout;
using std::endl;

int getNext( int n ) {
  int tmp = n;
  int pos = 0;

  // Step1: Find first "01" in n scanning from right to left
  bool one = false;
  bool zeroOne = false;
  while( pos < 31 ) {
    if( ( tmp & 1 ) == 1 ) {
      one = true;
    } else {
      if( one ) {
	zeroOne = true;
	break; 	// found first "01" scannig from right to left
      }
    }
    pos++;
    tmp = tmp >> 1;
  }
  
  if( not zeroOne ) {
    return -1; // this is the highest possible no
  }

  // Step2: Replace "01" by "10"
  int mask = 0x3 << ( pos - 1 ); // pos can't be less than 1 i.e 0 posn in "01"
  n = n ^ mask;

  // Step3: Now shift all bits before "pos - 2" to the right.
  tmp = n;
  pos = pos - 2;
  mask = 0; // new mask to set 1s
  while( pos > 0 ) {
    if( ( tmp & 1  ) == 1 ) {
      mask = mask << 1;
      mask = mask | 1;
    }
    pos--;
    tmp = tmp >> 1;
  }

  return n | mask;
}

int main() {
  cout << "Next of 15 " << getNext( 15 ) << endl;
  cout << "Next of 20 " << getNext( 20 ) << endl;
  return 0;
}

/* Conversion:
   Write a function to determine the number of bits you would need to flip to convert
   integer A to integer B.

   EXAMPLE
   Input: 29 ( or: 11101 ) , 15 ( or:  1111 )
   Output: 2
 */

#include <iostream>
using std::cout;
using std::endl;

// Each 1 in the XOR represents a bit that is different between A and B.
// Therefore, to check the number of bits that are different between A
// and B, we simply need to count the number of bits in A^B that are 1.

// Alternate approach:
// The operation c = c & (c - 1) will clear the least significant bit in c.
int bitCountInAxorB( int a, int b ) {
  int count = 0;

  for( int i = a^b; i != 0; i = i * ( i-1 ) )
    count++;

  return count;
}

int main() {
  return 0;
}

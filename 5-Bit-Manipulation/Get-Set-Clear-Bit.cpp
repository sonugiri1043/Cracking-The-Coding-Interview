#include <iostream>
using std::cout;

bool getBit( int num, int i ) {
  return ( num & ( 1 << i ) ) != 0 ;
}

int setBit( int num, int i ) {
  return num | ( 1 << i );
}

int clearBit( int num, int i ) {
  int mask = ~( 1 << i );
  return num & mask; 
}

// clear all bits from i through 0 (inclusive)
int clearBitsIthrough0(int num, int i) {
  int mask = ( -1 << ( i + 1 ) );
  return num & mask;
}

// set the ith bit to a value v
int updateBits( int num, int i, bool bitIs1 ) {
  int value = bitIs1 ? 1 : 0;
  int mask = ~( 1 << i );
  return ( num & mask ) | ( value << i );
}

int main() {
  return 0;
}

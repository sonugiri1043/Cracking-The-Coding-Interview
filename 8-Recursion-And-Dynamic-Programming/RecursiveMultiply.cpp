/*
  Recursive Multiply:
  Write a recursive function to multiply two positive integers without using the * operator.
  You can use addition, subtraction, and bit shifting, but you should minimize the number of
  those operations.
 */

#include <iostream>

using std::cout;
using std::endl;

// Assumes b is smaller than a
int multiply( int a, int b ) {
  int result = 0;
  while( b ) {
    if( b & 1 ) {
      result += a;
    }
    b = b >> 1;
    a = a << 1;
  }
  return result;
}

int main() {
  cout<< multiply( 15, 12 ) << endl;
  cout<< multiply( 35, 31 ) << endl;
  return 0;
}

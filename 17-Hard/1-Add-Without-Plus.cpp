/*
  Add Without Plus:
  Write a function that adds two numbers. You should not use + or any arithmetic
  operators.

  Solution:
  1. If we add two binary numbers together, but forget to carry, the i th bit in the sum
  will be 0 only if a and b have the same ith bit( both 0 or both 1 ). This is essentially
  an XOR.
  2. If we add two numbers together but only carry, we will have a 1 in the ith bit of the
  sum only if bits i - 1 of a and b are both 1s. This is an AND, shifted.
  3. Now, recurse until there's nothing to carry.
*/

// g++ 1-Add-Without-Plus.cpp --std=c++11

#include <iostream>

using std::cout;
using std::endl;

int add( int a, int b ) {
  int res;
  int carry;

  res = a ^ b;
  carry = (a & b ) << 1;
  if( carry > 0 ) {
    return add( res, carry );
  }
  return res;
}

int main() {
  int a = 112;
  int b = 47;
  cout<< add( a, b ) << endl;
}

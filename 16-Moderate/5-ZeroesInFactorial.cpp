/*
  Factorial Zeros:
  Write an algorithm which computes the number of trailing zeros in n factorial.

  Sol:
  A simple approach is to compute the factorial, and then count the number of trailing zeros
  by continuously dividing by ten. The problem with this though is that the bounds of an int
  would be exceeded very quickly. To avoid this issue, we can look at this problem mathematically.

  Consider a factorial like 19! :
    19! = 1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19

  A trailing zero is created with multiples of 10, and multiples of 10 are created with pairs
  of 5-multiples and 2-multiples.

  Therefore, to count the number of zeros, we only need to count the pairs of multiples of 5 and 2.
  There will always be more multiples of 2 than 5, though, so simply counting the number of multiples
  of 5 is sufficient.

  One "gotcha" here is 15 contributes a multiple of 5 (and therefore one trailing zero), while 25
  contributes two (because 25 = 5 * 5).
 */

#include <iostream>

using std::cout;
using std::endl;

int countZerosInFactorial( int N ) {
  int zeros = 0;
  for( int i=1; i*5 <= N; ++i ) {
    int n = i;
    while( n >= 5 ) {
      ++zeros;
      n = n/5;
    }
  }
  return zeros;
}

int main() {
  countZerosInFactorial( 19 );
  return 0;
}

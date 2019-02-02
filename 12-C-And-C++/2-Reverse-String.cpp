/*
  Implement a function void reverse( char* str) in C or C++ which
  reverses a null terminated string.
 */

#include <iostream>

using namespace std;

void reverseString( string &input ) {
  int start = 0;
  int end = input.length();

  char tmp;
  while( start <= end ) {
    tmp = input[ start] ;
    input[ start ] = input[ end ];
    input[ end ] = tmp;

    start++;
    end--;
  }
}

int main() {
  string text = "This is a string. Reverse it.\0";
  cout<< text << endl;
  reverseString( text );
  cout<< text << endl;
  return 0;
}

/*
  Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print
  the binary representation. If the number cannot be represented accurately in binary with at most 32
  characters, print "ERROR:'
 */

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

string binaryToString( double num ) {
  if( num > 1 || num < 0 ) {
    return "ERROR";
  }

  int len = 0;
  string binaryRep = "";
  while( num > 0 && len < 32 ) {
    num = num * 2;
    if( num >= 1 ) {
      binaryRep = binaryRep + "1";
      num = num - 1;
    } else {
      binaryRep= binaryRep + "0";
    }

    len++;
  }
  return binaryRep;
}

int main() {
  cout<< binaryToString( 0.72 ) << endl;
  cout<< binaryToString( 0.70 ) << endl;
  cout<< binaryToString( 0.95 ) << endl;
  return 0;
}

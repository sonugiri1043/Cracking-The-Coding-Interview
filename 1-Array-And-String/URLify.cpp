/*
 * Write a method to replace all spaces in a string with '%20' You may assume that
 * the string has sufficient space at the end to hold the additional characters, and
 * that you are given the "true" length of the string.
 *
 * Input:  "Mr John Smith    " 13
 * Output: "Mr%20John%20Smith"
 */

#include <iostream>

using namespace std;

string replaceSpaceInString( string &input, int len ) {
  int spaceCount = 0;
  for( int i = 0; i < len; i++ ) {
    if( input[ i ] == ' ' )
      spaceCount++;
  }

  int trueLen = len + spaceCount*2;
  int index = trueLen - 1;

  for( int i = len - 1; i >= 0; i-- ) {
    if( input[ i ] != ' ' ) {
      input[ index ] = input[ i ];
      index = index - 1;
    } else {
      input[ index ] = '0';
      input[ index - 1 ] = '2';
      input[ index - 2 ] = '%';
      index = index - 3;
    }
  }
  return input;
}


int main() {
  string s = "Mr John Smith    ";
  cout<< "Original input: " << s << endl; 
  cout<< "Modified input: " << replaceSpaceInString( s, 13 ) << endl;
  return 0;
}

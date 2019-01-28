/*
  Implement a method to perform basic string compression using the counts of
  repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
  If the "compressed" string would not become smaller than the original string,
  your method should return the original string.
  You can assume the string has only uppercase and lowercase letters (a - z).
*/

#include <iostream>
#include <string>

using namespace std;

string compressString( string &input ) {
  string result = "";
  int count;
  int index = -1;

  for( int i = 0; i < input.length();  ){
    count = 1;
    while( input[ i ] == input[ i + count ]
	   && ( i + count <= input.length() ) ) {
      count++;
    }
    i = i + count;

    result += input[ i ];
    result += to_string( count );
  }
  
  if( result.length() >= input.length() )
    return input;
  else
    return result;
}

int main() {
  string s1 = "aabcccccaaa";
  cout<< "Original string: " << s1 << endl;
  cout<< "Compressed string: " << compressString( s1 ) << endl;
  return 0;
}

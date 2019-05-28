/*
  Pattern Matching: 
  You are given two strings, pattern and value. The pattern string consists of just the letters
  a and b, describing a pattern within a string. For example, the string catcatgocatgo matches
  the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b.
  Write a method to determine if value matches pattern.

  Solution:
  Brute Force
  Iterating through all substrings for a and all possible substrings for b. There are O(n^2)
  substrings in a string of length n, so this will actually take O(n^4) time. But then, for
  each value of a and b, we need to build the new string of this length and compare it for equality.
  This building/comparison step takes O(n) time, giving an overall runtime of 0 (n^5).

  for each possible substring a
     for each possible substring b
        candidate = buildFromPattern(pattern, a, b)
        if candidate equals value
           return true	   
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string buildPattern( string a, string b, string pattern ) {
  string result = "";
  for( int i=0; i < pattern.length(); ++i ) {
    if( pattern[i] == 'a' ) {
      result = result + a;
    } else {
      result = result + b;
    }
  }
  return result;
}

bool isPatternInValue( string pattern, string value ) {
  // look for pattern in value
  return true;
}

bool patternMatchingV1( string pattern, string value ) {
  if( pattern.length() == 0 ) {
    return value.length() == 0;
  }
  
  // get all sub-string
  for( int i=0; i < value.length(); ++i ) {
    for( int j=1; j + i <= value.length(); ++j ) {
      string s = value.substr( i, j );
      cout<< s << endl;
    }
  }
  // for all sub-string build pattern
  string res = buildPattern( "cat", "go", pattern );
  cout<< res << endl;
  return isPatternInValue( res, value );
}

int main() {
  string pattern = "aabab";
  string value = "catcatgocatgo";
  
  patternMatchingV1( pattern, value );
  return 0;
}

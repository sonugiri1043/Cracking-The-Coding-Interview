/*
  There are three types of edits that can be performed on strings: insert a character,
  remove a character, or replace a character. Given two strings, write a function to
  check if they are one edit (or zero edits) away.
  EXAMPLE
  pale, ple   -> true
  pales, pale -> true
  pale, bale  -> true
  pale, bake  -> false
 */

#include <iostream>

using namespace std;

bool checkReplacement( string s1, string s2 ) {
  bool diffFound = false;
  for( int i = 0; i < s1.length(); i++ ) {
    if( s1[ i ] != s2[ i ] ) {
      if( diffFound ) {
	return false;
      }
      diffFound = true;
    }
  }
  return true;
}

bool checkRemove( string &s1, string &s2 ) {
  bool diffFound = false;
  int j = 0; // index in string s2
  for( int i = 0; i < s1.length(); i++, j++ ) {
    if( s1[ i ] != s2[ j ] ) {
      i++;
      if( diffFound )
	return false;
      diffFound = true;
    }
  }
  return true;
}

bool isStringOneEditAway( string &s1, string &s2 ) {
  // If string s1 and s2 are of equal length then check for replaceement
  // else check for remove( removing 1 char from larger string should
  // give smaller string ).
  // Insert is opposite of remove.

  if( s1.length() == s2.length() ) {
    return checkReplacement( s1, s2 );
  } else {
    if( s1.length() - 1 == s2.length() )
      return checkRemove( s1, s2 );
    if( s2.length() - 1 == s1.length() )
      return checkRemove( s2, s1 );
  }
  return false;
}

int main() {
  string a1 = "pale";
  string a2 = "ple";
  cout<< isStringOneEditAway( a1, a2 ) << endl;

  string b1 = "pales";
  string b2 = "pale";
  cout<< isStringOneEditAway( b1, b2 ) << endl;
  
  string c1 = "pale";
  string c2 = "bale";
  cout<< isStringOneEditAway( c1, c2 ) << endl;

  string d1 = "pale";
  string d2 = "bake";
  cout<< isStringOneEditAway( d1, d2 ) << endl;
  return 0;
}

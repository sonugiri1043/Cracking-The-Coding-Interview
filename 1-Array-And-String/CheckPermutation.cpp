/*
 Given two strings, write a method to decide if one is a permutation of the other.
 
 Assumption:
 ASCII string.

 Ques to ask:
 Is case sensitive;
 Is white-space significant.
 */

#include <iostream>

using namespace std;

bool checkPermutation( string string1, string string2 ) {
  // Check if the two strings have identical character counts.
  if( string1.length() != string2.length() ) {
    return false;
  }
  int xorValue=0;
  for(char ch : string1){
    xorValue^=ch;
  }
  for(char ch : string2){
    xorValue^=ch;
  }
  return xorValue==0;
}

bool checkPermutationUsingSorting( string input1, string input2 ) {
  sort( input1.begin(), input1.end() );
  sort( input2.begin(), input2.end() );
  if( input1 == input2 )
    return true;
  return false;
}

int main() {
  cout<< "Program to check if two strings are permutations of each other" << endl;
  string s1 = "hey how are you ?";
  string s2 = "how are uoy yeh ?";
  string s3 = "how are uoy yeh h ?";
  
  cout<< checkPermutation( s1, s2 ) << endl;
  cout<< checkPermutation( s1, s3 ) << endl;
  cout << checkPermutationUsingSorting( s1, s2 ) << endl;
  cout << checkPermutationUsingSorting( s1, s3 ) << endl;
  return 0;
}

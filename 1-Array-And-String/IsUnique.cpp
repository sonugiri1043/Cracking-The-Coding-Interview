#include <iostream>
#include <string>

using namespace std;

/*
  Implement an algorithm to determine if a string has all unique characters.

  Notes:
  ASCII is a 7-bit code, representing 128 different characters.

  Ques to Ask:
  Is string ASCII or Unicode ?

  We assume ASCII for this example.
*/

bool isDupUsingHashTable( string input ) {
  if( input.length() > 128 ) {
    return true;
  }

  for(int i=0;i<input.length();i++){
    for(int j=i+1;j<input.length();j++){
      if(input[i]==input[j])
        return true;
    }
  }
  return false;
}

int main() {
  string s = "Not Duplicate";
  string s1 = "Not Duplicae";
  cout<< isDupUsingHashTable( s ) << endl;
  cout<< isDupUsingHashTable( s1 ) << endl;  
  return 0;
}

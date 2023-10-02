/*
 * Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards. A permutation
 * is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
 * EXAMPLE
 * Input: Tact Coa
 * Output: True (permutations: "taco cat". "atco cta". etc.)
 */
#include <iostream>

using namespace std;

bool canFormPalindrome( string input ) {
   int charFreqCount[26] = {0};

    for (char c : input) {
        if (isspace(c)) continue;
        if (isalpha(c)) {
            charFreqCount[tolower(c) - 'a']++;
        }
    }

    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (charFreqCount[i] % 2 != 0) {
            oddCount++;
        }
    }

    return oddCount <= 1;
  }
  
  if( charCount % 2 != 0 && oddCount == 1 ) {
    return true;
  }
  return false;
}

int main() {
  cout<< "Program to check if a string can form a palindrome" << endl;
  string s1 = "Tact Coa";
  string s2 = "taco cat";
  string s3 = "atco cta";
  string s4 = "atca ct t b";

  cout<< canFormPalindrome( s1 ) << endl;
  cout<< canFormPalindrome( s2 ) << endl;
  cout<< canFormPalindrome( s3 ) << endl;
  cout<< canFormPalindrome( s4 ) << endl;
  return 0;
}

/* English Int:
   Given any integer, print an English phrase that describes the integer
   ( e.g. "One Thousand, Two Hundred Thirty Four"). */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;

class IntToEnglish {
  static const vector< string > digitMap;
  static const vector< string > tens;
  static const vector< string > bigs;

  string intToEngHelper( int num ) {
    string out="";
    if( num > 100 ) {
      int div = num / 100;
      out += digitMap[ div ] + " hundred ";
      num = num % 100;
      if( num < 20 ) {
	out += digitMap[ num ];
      } else {
	div = num/10;
	out += tens[ div - 2 ]; // since index stars from "twenty"
	out += " " + digitMap[ num % 10 ];
      }
    }
    return out;
  }

public:
  string intToEng( int number ) {
    if( number == 0 ) {
      return digitMap[ number ];
    }
    if( number < 0 ) {
      return "Negative " + intToEng( -1*number );
    }
    int bigsIndex = 0;
    stack< string> s;
    while( number > 1000 ) {
      s.push( bigs[ bigsIndex ] );
      s.push( intToEngHelper( number % 1000 ) );
      number = number / 1000;
      bigsIndex += 1;
    }
    if( number > 0 ) {
      s.push( bigs[bigsIndex] );
      s.push( intToEngHelper( number ) );
    }
    string output = "";
    while( !s.empty() ) {
      output += " " + s.top();
      s.pop();
    }
    return output;
  }
};

const vector<string> IntToEnglish::digitMap = { "zero", "one", "two", "three", "four",
						"five", "six", "seven", "eight", "nine",
						"ten", "eleven", "twelve", "thirteen",
						"fourteen", "fifteen", "sixteen", "seventeen",
						"eighteen", "ninteen" };
const vector<string> IntToEnglish::tens = { "twenty", "thirty", "fourty", "fifty", "sixty",
					    "seventy", "eighty", "ninty" };
const vector<string> IntToEnglish::bigs = { "", "thousand", "million", "billlion" };

int main() {
  IntToEnglish intToEng;
  cout << "764542: " << intToEng.intToEng( 764542 ) << endl;
  cout << "542: " << intToEng.intToEng( 542 ) << endl;
  cout << "134765542: " << intToEng.intToEng( 134765542 ) << endl;
  return 0;
}

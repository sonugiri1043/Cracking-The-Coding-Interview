/*
  Living People: 
  Given a list of people with their birth and death years, implement a method to compute the
  year with the most number of people alive. You may assume that all people were born between
  1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should
  be included in that year's count. For example, Person (birth = 1908, death = 1909) is included
  in the counts for both 1908 and 1909.
*/

// g++ 10-No-Of-Living-People.cpp --std=c++14

#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::set;

struct Person {
  int yearOfBirth;
  int yearOfDeath;
  
  Person( int yearBirth, int yearDeath  ) {
    yearOfBirth = yearBirth;
    yearOfDeath = yearDeath;
  }
};

struct Year {
  int year;
  bool birth;

  Year( int year_, bool birth_ ) { 
    year = year_;
    birth = birth_;
  }
  
  bool operator< ( const Year &y ) const {
    return year < y.year;
  }
};

int main() {
  vector<Person> persons = { Person( 12, 15 ), Person( 20, 90 ), Person( 10, 98 ),
			     Person( 01, 72 ), Person( 10, 98 ), Person( 23, 82 ),
			     Person( 13, 98 ), Person( 90, 98 ), Person( 83, 99 ),
			     Person( 75, 94 ) };

  vector< Year > years;
  for( auto person : persons ) {
    years.push_back( Year( person.yearOfBirth, true ) );
    // added 1 since death year is also included.
    years.push_back( Year( person.yearOfDeath + 1, false ) );
  }

  std::sort( years.begin(), years.end() );

  int maxPeople = 0;
  int maxYear = 0;
  int tmp = 0;
  for( auto y : years ) {
    if( y.birth ) {
      tmp += 1;
      if( tmp > maxPeople ) {
	maxPeople = tmp;
	maxYear = y.year;
      }
    } else {
      tmp -= 1;
    }
  }

  cout<< "Max people alive " << maxPeople << " in year " << maxYear << endl;
  return 0;
}


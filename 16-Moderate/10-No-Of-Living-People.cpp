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

using std::cout;
using std::endl;
using std::vector;

struct Person {
  int yearOfBirth;
  int yearOfDeath;
  
  Person( int yearBirth, int yearDeath  ) {
    yearOfBirth = yearBirth;
    yearOfDeath = yearDeath;
  }
};

int main() {
  vector<Person> persons = { Person( 12, 15 ), Person( 20, 90 ), Person( 10, 98 ),
			     Person( 01, 72 ), Person( 10, 98 ), Person( 23, 82 ),
			     Person( 13, 98 ), Person( 90, 98 ), Person( 83, 99 ),
			     Person( 75, 94 ) };
  return 0;
}














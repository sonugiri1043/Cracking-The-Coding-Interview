#include <iostream>

using namespace std;

#define NAME_SIZE 50

class Person {
  int id;
  char name[ NAME_SIZE ];
public:
  virtual ~Person() {
    cout << "Deleting person" << endl;
  }
  virtual void aboutMe() {
    cout<< "I'm a person" << endl;
  }
  // "addCourse" is a pure virtual function. Person is an
  // abstract class and we cannot instantiate it.
  virtual bool addCourse( string s ) = 0;
  void report() {
    cout<< "Person reporting" << endl;
  }
};

class Student : public Person {
public:
  ~Student() {
    cout<< "Deleting student" << endl;
  }
  void aboutMe() {
    cout << "I'm a student" << endl;
  }
  void report() {
    cout<< "Student reporting" << endl;
  }
  bool addCourse( string s ) {
    cout<<"Added course " << s << "to student" << endl;
    return true;
  }
};

int main() {
  /*commented out because Person is an abstract class because
    addCourse is a pure virtual function. Abstract class cannot
    be instantiate.
  
    Person *p1 = new Person();
    p1->aboutMe(); // prints "I'm a person"
    p1->report();  // prints "Person reporting"
    delete p1; */

  Person *p2 = new Student();
  p2->aboutMe(); // prints "I'm a student"
  p2->report(); // prints "Person reporting"
  // This is because the function reporting is resolved at
  // compile time, in a mechanism known as "static binding".
  delete p2;
  
  Student *p3 = new Student();
  p3->aboutMe(); // prints "I'm a student"
  p3->report(); // prints "Student reporting"
  delete p3;
  return 0;
}

#include <iostream>

using namespace std;

#define NAME_SIZE 50

class Person {
  // By default all members are private
  int id;
  char name[ NAME_SIZE ];

public:
  void aboutMe() {
    cout<< "I'm a person." << endl;
  }
};

class Student : public Person {
public:
  void aboutMe() {
    cout<< "I'm a student" << endl;
  }
};

int main() {
  Student *student = new Student();
  student->aboutMe(); // prints "I'm a student"

  delete student; // Imp! Make sure to delete allocated memory
  return 0;
}

/* Imp points on Constructor and Distructor
   1. The constructor of a class is automatically called upon an object's creation.
   2. If no constructor is defined, the compiler automatically generates one called
      the Default Constructor.
   3. Person( int a ) : id(a) {
      }
    The data member id is assigned before the actual object is created and before the
    remainder of the constructor code is called. This approach is necessary when the
    fields are constant or class types.
   4. The destructor cleans up upon object deletion and is automatically called when an
    object is destroyed. It cannot take an argument as we don't explicitly call a destructor.
 */

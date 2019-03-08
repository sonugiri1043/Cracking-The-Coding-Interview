#include <string>    // std::string 
#include <iostream>  // std::cout, std::endl

using std::string;
using std::cout;
using std::endl;

enum Level {
  RESPONDENT = 1,
  MANAGER,
  DIRECTOR,
};

// Forward declaration of Employee Class
class Employee;

class Call {
  string phoneNo;
  Level level;

  /* Note: Employee has to be pointer as we don't know about Employee
     class layout at this point */
  Employee *handler;
  
 public:
  Call( string phoneNo ) {
    phoneNo = phoneNo;
    level = Level::RESPONDENT;
  }
  Level getLevel() {
    return level;
  }
  void setLevel( Level _level ) {
    level = _level;
  }
};

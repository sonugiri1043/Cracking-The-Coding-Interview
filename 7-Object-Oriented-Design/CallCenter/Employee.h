#include "Call.h"

enum Level {
  RESPONDENT = 1,
  MANAGER,
  DIRECTOR,
};

class Employee {
  int employeeId;
  Level level;
  Call *call;

 public:
  void setId( int id ) {
    employeeId = id;
  }

  void setLevel( Level level ) {
    level = level;
  }

  void setCall( Call *c ) {
    call = c;
  }

  bool isAvailable() {
    return call == NULL;
  }
};

class Respondent : public Employee {
 public:
  Respondent( int id ) {
    setId( id );
    setLevel( Level::RESPONDENT );
    setCall( NULL );
  }
};

class Manager : public Employee {
 public:
  Manager( int id ) {
    setId( id );
    setLevel( Level::MANAGER );
    setCall( NULL );
  }
};

class Director : public Employee {
 public:
  Director( int id ) {
    setId( id );
    setLevel( Level::DIRECTOR );
    setCall( NULL );
  }
};

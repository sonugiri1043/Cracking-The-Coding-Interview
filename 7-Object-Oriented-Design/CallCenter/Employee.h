#include <assert.h>  // assert
#include "Call.h"

// Forward declaration of CallHandler
class CallHandler;

class Employee {
  int employeeId;
  Level level;
  Call *call;
  CallHandler *callHandler;

ublic:
  void setId( int id ) {
    employeeId = id;
  }
  void setLevel( Level level ) {
    level = level;
  }
  void setCall( Call *c ) {
    call = c;
  }
  void setCallHandler( CallHandler *callHandler ) {
    callHandler = callHandler;
  }

  // check for availability
  bool isAvailable() {
    return call == NULL;
  }
  
  // Receive a call
  void receiveCall( Call *c ) {
    assert( call == NULL );
    call = c;
  }
  
  // Disconnect an ongoing call
  void disconnectCall() {
    delete call;
    call = NULL;
  }

  // Escalate to higher level
  void escalate();
};

/* Respondent */
class Respondent : public Employee {
 public:
  Respondent( int id, CallHandler *callHandler ) {
    setId( id );
    setLevel( Level::RESPONDENT );
    setCall( NULL );
    setCallHandler( callHandler );
  }
};

/* Manager */
class Manager : public Employee {
 public:
  Manager( int id, CallHandler *callHandler ) {
    setId( id );
    setLevel( Level::MANAGER );
    setCall( NULL );
    setCallHandler( callHandler);
  }
};

/* Director */
class Director : public Employee {
 public:
  Director( int id, CallHandler *callHandler ) {
    setId( id );
    setLevel( Level::DIRECTOR );
    setCall( NULL );
    setCallHandler( callHandler);
  }
};

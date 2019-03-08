/*
  Compile using 'g++ CallHandler.cpp -o CallHandler --std=c++11'
 */

#include <list>    // std::list
#include <queue>   // std::queue

#include "Employee.h"

using std::list;
using std::queue;

class CallHandler {
  list< Director * > directors;
  list< Manager * > managers;
  list< Respondent * > respondents;
  queue< Call * > callQueue;
  
public:
  CallHandler( int numRespondents, int numManagers,
	       int numDirectors ) {
    for( int i = 0; i < numRespondents; i++ ) {
      respondents.push_back( new Respondent( i, this ) ) ;
    }
    for( int i = 0; i < numManagers; i++ ) {
      managers.push_back( new Manager( i, this ) );
    }
    for( int i = 0; i < numDirectors; i++ ) {
      directors.push_back( new Director( i, this ) );
    } 
  }
  
  void putCallOnQueue( Call *c ) {
    callQueue.push( c );
  }

  void dispatchCall( string phoneNo ) {
    Call *c = new Call( phoneNo );
    callQueue.push( c );
    handleCall();
  }
  
  void handleCall() {
    if( callQueue.empty() ) {
      return;
    }
    Call *call = callQueue.front();
    // TODO
    // check rank of call and find a free employee of that level
    // and assign call to that emmployee
    callQueue.pop();
    if( !callQueue.empty() ) {
      handleCall();
    }
  }
};

// We need to define this here since callHandler is a forward declaration
// in Employee Method and it access it's member fn
void Employee::escalate() {
  if( call->getLevel() == Level::RESPONDENT ) {
    call->setLevel( Level::MANAGER );
  } else if ( call->getLevel() == Level::MANAGER ) {
    call->setLevel( Level::DIRECTOR );
  }
  callHandler->putCallOnQueue( call );
  call = NULL;
}

int main() {
  CallHandler *callHandler = new CallHandler( 20, 4, 2 );
  return 0;
}

#include <list>
#include <queue>

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
      respondents.push_back( new Respondent( i ) ) ;
    }

    for( int i = 0; i < numManagers; i++ ) {
      managers.push_back( new Manager( i ) );
    }

    for( int i = 0; i < numDirectors; i++ ) {
      directors.push_back( new Director( i ) );
    } 
  }

};

int main() {
  CallHandler *callHandler = new CallHandler( 20, 4, 2 );
  return 0;
}

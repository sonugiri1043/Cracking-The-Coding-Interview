#include "CircularArray.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  int capacity = 100;
  CircularArray<int>* ca = new CircularArray<int>( capacity );  
  for( int i = 0; i < 80; i++ ) {
    ca->push_back( i*2 );
  }
  cout<< "size " << ca->getSize() << endl;
  
  for( int i=0; i < 40; i++ ) {
    ca->push_back( i*2 );
  }
  cout<< "size " << ca->getSize() << endl;
  return 0;
}

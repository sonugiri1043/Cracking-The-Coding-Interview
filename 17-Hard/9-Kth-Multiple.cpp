/*
  Kth Multiple: Design an algorithm to find the kth number such that the only prime factors are 3, 5,
  and 7. Note that 3,5, and 7 do not have to be factors, but it should not have any other prime factors.
  For example, the first several multiples would be (in order) 1,3, 5, 7, 9, 15, 21.
 */

#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

int getKthMultiple( int x, int y, int z, int k ) {
  queue<int> qX, qY, qZ;
  qX.push(1);
  qX.push(x);
  qY.push(y);
  qZ.push(z);
  int min;
  for( int i=0; i < k; i++ ) {
    min = qX.front() < qY.front() ? ( qX.front() < qZ.front() ? qX.front() : qZ.front() ) : (qY.front() < qZ.front() ? qY.front() : qZ.front() );
    if( min == qX.front() ) {
      qX.pop();
      qX.push( min * x );
      qY.push( min * y );
      qZ.push( min * z );
    }
    if( min == qY.front() ) {
      qY.pop();
      qY.push( min * y );
      qZ.push( min * z );
    }
    if( min == qZ.front() ) {
      qZ.pop();
      qZ.push( min * z ); 
    }
  }
  return min;
}

int main() {
  int k = 10;
  int x = 3, y = 5, z = 7;
  cout<< getKthMultiple( x, y, z, 10 ) << endl;
}

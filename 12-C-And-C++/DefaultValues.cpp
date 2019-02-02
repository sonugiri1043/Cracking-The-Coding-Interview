#include <iostream>

using namespace std;

int func( int a, int b=3 ) {
  return a + b;
}

int main() {
  cout<< "Default values " << endl;
  cout<< func( 10 ) << endl;
  cout<< func( 10, 20 ) << endl;
  return 0;
}

/*
  Write a method to print the last K lines of an input file using C++.

  Note:
  C++ provides the following classes to perform output and input of
  characters to/from files: 

  ofstream: Stream class to write on files.
  ifstream: Stream class to read from files.
  fstream: Stream class to both read and write from/to files.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
  char *filename = "text.txt";
  const int k = 10; // last 10 lines
  string line[k]; // circular array to hold 10 lines
  int size = 0;

  ifstream infile;
  infile.open( filename );
  
  /* Read file line by line into circular array */
  while( infile.peek() != EOF ) {
    getline( infile, line[ size % k ] );
    size++;
  }
  infile.close();

  // compute start of circular array, and size of it
  int start = size > k ? ( size % k ) : 0;
  int count = min( k, size );
  
  for( int i = 0; i < count; i++ ) {
    cout<< line[ ( start + i ) % k ] << endl;
  }
  return 0;
}

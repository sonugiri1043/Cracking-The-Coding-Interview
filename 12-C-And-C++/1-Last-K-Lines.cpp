/*
  Write a method to print the last K lines of an input file using C++.

  Note:
  C++ provides the following classes to perform output and input of
  characters to/from files: 

  ofstream: Stream class to write on files.
  ifstream: Stream class to read from files.
  fstream: Stream class to both read and write from/to files.

  These classes are derived directly or indirectly from the classes
  istream and ostream. We have already used objects whose types were
  these classes: cin is an object of class istream and cout is an object
  of class ostream. Therefore, we have already been using classes that are
  related to our file streams. And in fact, we can use our file streams
  the same way we are already used to use cin and cout, with the only
  difference that we have to associate these streams with physical files.
  Let's see an example:

  // basic file operations
  #include <iostream>
  #include <fstream>
  using namespace std;
  
  int main () {
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
  }
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

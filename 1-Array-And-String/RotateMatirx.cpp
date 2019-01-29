/* Given an image represented by an NxN matrix, where each pixel in the image is 4
   bytes, write a method to rotate the image by 90 degrees. can you do this in place?
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void printArray( int A[11][11], int n ) {
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }  
}

void rotate90( int ( &A )[11][11], int N ) {
  int tmp;
  int max = N;
  for( int i = 0; i < max; i++ ) {
    for( int j = i; j < max - 1; j++ ) {
      // Only consider col 0 - maxCol-2, otheriwise corner element will 
      // get replaced twice.
      tmp = A[ i ][ j ];
      A[ i ][ j ] = A[ j ][ max - 1 ]; 
      A[ j ][ max - 1 ] =  A[ max - 1 ][ max - j - 1 ];
      A[ max - 1 ][ max - j - 1 ] = A[ max - j - 1 ][ i ];
      A[ max - j - 1 ][ i ] = tmp; 
    }
    // each time max will reduce by 2 rows and 2 cols
    max--;
  }
}

int main() {
  int arr[ 11 ][ 11 ];
  int N = 11;
  for( int i = 0; i < N; i++ ) {
    for( int j = 0; j < N; j++ ) {
      arr[i][j] = rand() % 10;
    }
  }
  
  cout<< "Original 2-D Array: " << endl;
  printArray( arr, N );
  rotate90( arr, N );
  cout<< "90 degree rotated arrat: " << endl;
  printArray( arr, N );  
  return 0;
}

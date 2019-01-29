/*
  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
  column are set to O.
 */

#include <iostream>
#include <set>

using namespace std;

void initMatrix( int (&Arr)[10][10], int N ) {
  for( int i=0; i<N; i++ ) {
    for( int j=0; j<N; j++ ) {
      Arr[i][j] = rand()%10;
    }
  }
  return;
}

void printMatrix( int (&Arr)[10][10], int N ) {
  for( int i=0; i<N; i++ ) {
    for( int j=0; j<N; j++ ) {
      cout << Arr[i][j] << " ";
    }
    cout << endl;
  }
}

void replaceRowAndColWithZero( int (&Arr)[10][10], int N ) {
  set< int, greater<int> > rows;
  set< int, greater<int> > cols;
  for( int i=0; i<N; i++ ) {
    for( int j=0; j<N; j++ ) {
      if( Arr[i][j] == 0 ) {
	rows.insert( i );
	cols.insert( j );
      }
    }
  }

  set< int, greater<int> >::iterator it;
  for( it=rows.begin(); it != rows.end(); it++ ) {
    for( int i=0; i<N; i++ ) {
     Arr[ *it ][i] = 0;
    }
  }

  for( it=cols.begin(); it != cols.end(); it++ ) {
    for( int i=0; i<N; i++ ) {
     Arr[ i ][*it] = 0;
    }
  }
}

int main() {
  int Arr[10][10];
  initMatrix( Arr, 10 );
  cout<< "Original Matrix" << endl;
  printMatrix( Arr, 10 );
  replaceRowAndColWithZero( Arr, 10 );
  cout<< "Replace row and column with zero" << endl;
  printMatrix( Arr, 10 );
  return 0;
}

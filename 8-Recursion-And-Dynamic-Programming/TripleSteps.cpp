/*
  Triple Steps:
  A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
  Implement a method to count how many possible ways the child can run up the stairs.
 */

#include <iostream>

using std::cout;
using std::endl;

int getways( int n ) {
  int arr[n + 1];
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for( int i = 3; i <= n; i++ ) {
    arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
  }
  return arr[n];
}

int main() {
  int n = 10;
  cout<<  getways( n ) << endl;
  return 0;
}

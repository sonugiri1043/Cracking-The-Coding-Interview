/*
  Volume of Histogram:
  Imagine a histogram (bar graph). Design an algorithm to compute the
  volume of water it could hold if someone poured water across the top. You can assume that each
  histogram bar has width 1.
  EXAMPLE
  Input: {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0}
  Output: 26
 */

// g++ 21-Volume-Of-Histogram.cpp --std=c++11

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Bounds {
  unsigned int leftMax;
  unsigned int rightMax;
  Bounds() {
    leftMax = 0;
    rightMax = 0;
  }
  
  int getMin() {
    return leftMax > rightMax ? rightMax: leftMax;
  }
};

int getVolume( vector<int> arr ) {
  unsigned int vol = 0;
  vector<Bounds> bound( arr.size() );
  // get max from left side
  int max = 0;
  for( int i = 0; i < arr.size(); ++i ) {
    if( arr[i] > max )
      max = arr[i];
    bound[i].leftMax = max;
  }
  // get max from right side
  max = 0;
  for( int i = arr.size() - 1; i >=0; --i ) {
    if( arr[i] > max )
      max = arr[i];
    bound[i].rightMax = max;
  }
  // get volume
  for( int i = 0; i < arr.size(); ++i ) {
    vol += bound[i].getMin() - arr[i];
  }
  return vol;
}

int main() {
  vector<int> arr = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0};
  vector<int> arr1 = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
  cout << getVolume( arr ) << endl;
  cout << getVolume( arr1 ) << endl;
  return 0;
}

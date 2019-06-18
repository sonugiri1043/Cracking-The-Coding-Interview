/*
  The Masseuse:
  A popular masseuse receives a sequence of back-to-back appointment requests and is debating
  which ones to accept. She needs a 15-minute break between appointments and therefore she cannot
  accept any adjacent requests. Given a sequence of back-to-back appointment requests (all multiples
  of 15 minutes, none overlap, and none can be moved), find the optimal (highest total booked minutes)
  set the masseuse can honor. Return the number of minutes.

  EXAMPLE
  Input: {30, 15, 60, 75, 45, 15, 15, 45}
  Output: 180 minutes ({30, 60, 45, 45})

  INPUT: {75, 105, 120, 75, 90, 135}
  OUTPUT: 330 minutes ({75, 120, 135})
 */

// g++ 16-The-Masseuse.cpp --std=c++11

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int optimalBooking( const vector<int> input ) {
  int maxBooking=0;
  vector< int > max( input.size(), 0 );
  max[0] = input[0];
  max[1] = input[0] > input[1] ? input[0] : input[1];
  for( int i = 2; i < input.size(); i++ ) {
    if( max[i-2] + input[i] > max[ i-1 ] ) {
      max[ i ] = max[i-2] + input[i];
    } else {
      max[i] = max[i-1];
    }
    if( max[i] > maxBooking ) {
      maxBooking = max[i];
    }   
  }
  return maxBooking;
}

int optimalBookingV2( const vector<int> input ) { 
  int maxBooking=0;
  int max;
  int maxTwoAway = input[0];
  int maxOneAway = input[0] > input[1] ? input[0] : input[1];
  for( int i = 2; i < input.size(); i++ ) {
    if( maxTwoAway + input[i] > maxOneAway ) {
      max = maxTwoAway + input[i];
    } else {
      max = maxOneAway;
    }
    maxTwoAway = maxOneAway;
    maxOneAway = max;

    if( max > maxBooking ) {
      maxBooking = max;
    }    
  }
  return maxBooking;
}

int main() {
  vector<int> input1 = {30, 15, 60, 75, 45, 15, 15, 45};
  vector<int> input2 = {75, 105, 120, 75, 90, 135};
  cout<< optimalBooking( input1 ) << endl;
  cout<< optimalBooking( input2 ) << endl;
  cout<< optimalBookingV2( input1 ) << endl;
  cout<< optimalBookingV2( input2 ) << endl;
  return 0;
}

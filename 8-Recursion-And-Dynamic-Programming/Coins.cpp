/*
  Coins:
  Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents),
  and pennies (1 cent), write code to calculate the number of ways of representing n cents.
 */

#include <iostream> 
#include <vector> 
 
using std::cout; 
using std::endl; 
using std::vector; 
 
int getChangeWays( int amount, vector< int > & denom, int index ) { 
  if( index >= denom.size() - 1 ) return 1; // last denom                                                                                                                                                                                                  
  int denomAmount = denom[ index]; 
  int noOfWays = 0; 
  for( int i = 0; i * denomAmount <= amount; i++ ) { 
    int amountRem = amount - i * denomAmount; 
    noOfWays += getChangeWays( amountRem, denom, index + 1 ); 
  } 
  return noOfWays; 
} 
 
int makeChange( int amount, vector< int > & denom, int index, 
                vector< vector< int > > &map ) { 
  if( index >= denom.size() - 1 ) 
    return 1; 
  if( map[ amount][index] > 0 ) 
    return map[ amount ][index]; 
  int denomAmount = denom[ index]; 
  int noOfWays = 0; 
  for( int i = 0; i * denomAmount <= amount; i++ ) { 
    int amountRem = amount - i * denomAmount; 
    noOfWays += makeChange( amountRem, denom, index + 1, map ); 
  } 
  map[ amount ][ index ] = noOfWays; 
  return noOfWays; 
} 
 
int getChangeWaysV1( int amount, vector< int > &denom, int index ) { 
  vector< vector< int > > map; 
  for( int i = 0; i <= amount; i++ ) { 
    map.push_back( { 0, 0, 0, 0 } ); 
  } 
  return makeChange( amount, denom, index, map ); 
} 
 
int main() { 
  int n = 5; 
  vector< int > denom = { 25, 10, 5, 1 }; 
  cout<< getChangeWays( n, denom, 0 ) << endl;
  cout<< getChangeWaysV1( n, denom, 0 ) << endl;
  return 0;
}

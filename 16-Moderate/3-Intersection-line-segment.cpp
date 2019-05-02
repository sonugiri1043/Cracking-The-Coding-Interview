/*
  Intersection:
  Given two straight line segments ( represented as a start point and an end point )
  compute the point of intersection, if any.

  Two segments (p1,q1) and (p2,q2) intersect if and only if one of the following two conditions is verified

  General Case:
  – (p1, q1, p2) and (p1, q1, q2) have different orientations and
  – (p2, q2, p1) and (p2, q2, q1) have different orientations.

  https://www.geeksforgeeks.org/orientation-3-ordered-points/
 */

#include <iostream>

using std::cout;
using std::endl;

struct Point {
  int x;
  int y;

  Point( int _x, int _y ) {
    x = _x;
    y = _y;
  }
};

bool checkOrientation( Point p1, Point p2, Point p3, Point p4 ) {
/* Point p1-p2 represent a line;
   Point p3-p4 represent another line; */
  int slopeP1P2P3 = ( p2.y - p1.y )*( p3.x - p2.x ) - ( p3.y - p2.y )*( p2.x - p1.x );
  int slopeP1P2P4 = ( p2.y - p1.y )*( p4.x - p2.x ) - ( p4.y - p2.y )*( p2.x - p1.x );
  if( ( slopeP1P2P3 > 0 && slopeP1P2P4 > 0 ) ||
      ( slopeP1P2P3 < 0 && slopeP1P2P4 < 0) ) {
    return false;
  }
  return true;
}


int main() {
  Point A( 1, 2 );
  Point B( 3, 4 );
  Point C( 2, 6 );
  Point D( 5, 4 );
  int orie1 = checkOrientation( A, B, C, D );
  int orie2 = checkOrientation( C, D, A, B );
  if( orie1 != orie2 ) {
    cout<< "Lines don't intersect" << endl;
  }
  return 0;
}

/*
  Best Line: Given a two-dimensional graph with points on it, find a line which
  passes the most number of points.

  Solution: O( N^2) where N is number of points.
  Draw an infinite line (that is, not a line segment) between every two points and,
  using a hash table, track which line is the most common.
  
  We will represent a line as a slope and y-intercept (as opposed to a pair of points),
  which allows us to easily check to see if the line from (x1, y1) to (x2, y2) is equivalent
  to the line from (x3, y3) to (x4, y4).

  To find the most common line then, we just iterate through all lines segments, using a hash
  table to count the number of times we've seen each line.

  Input: [[1,1],[2,2],[3,3]]
  Output: 3

  Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
  Output: 4 */

// g++ 14-Best-Line.cpp --std=c++14

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Point {
public:
  int x;
  int y;

  Point( int x, int y ) : x(x), y(y) {}
};

class Line {
public:
  double slope;
  double intercept;

  Line( double slope, double intercept ) : slope( slope ), intercept( intercept ) {}
};

unordered_map<Line, int> lines;

void getLine( Point A, Point B ) {
  double slope = (B.y - A.y)/( B.x-B.y);
  double intercept = B.y - slope*B.x;
  // create line and populate hash table in the line is not there already.
}

void getBestLine( vector< Point> points ) {
  for( int i=0; i < points.size() - 1; ++i ) {
    for( int j=i+1; j < points.size(); ++j ) {
      getLine( points[i], points[j] );
    }
  }
  // iterate through hash map and return the line with max count
}

int main() {
  vector< Point > points1 = { Point(1,1), Point(2,2), Point(3,3) };
  vector< Point > points2 = { Point(1,1), Point(3,2), Point(5,3), Point(4,1),
			      Point(2,3), Point(1,4) };
  getBestLine( points1 );
  getBestLine( points2 );
  return 0;
}

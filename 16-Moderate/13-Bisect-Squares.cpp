/* Bisect Squares:

   Given two squares on a two-dimensional plane, find a line that would cut these two squares
   in half. Assume that the top and the bottom sides of the square run parallel to the x-axis.

   Sol: A line passing through the center of 2 square cuts both into half. */

#include <iostream>

class Square {
/*  
    Square re-presentation

(x,y+a) -------------   (x+a, y+a)
       |             |
       |             |
       |             |
       |             |
       |             |
(x,y)   -------------   (x+a, y) */
  double x;
  double y;
  double edge;

public:
  Square( double x_, double y_, double edge_ ) : x( x_ ), y( y_ ), edge( edge_ ) {}
  
  std::pair<double, double> getCenter() {
    return std::make_pair( this->x + this->edge/2, this->y + this->edge/2 );
  }

  std::pair<double, double> getIntersectingLine( Square &s ) {
    // TODO:
    // check if both circle have same center
    std::pair<double, double> a = this->getCenter();
    std::pair<double, double> b = s.getCenter();

    double slope = (a.second - b.second)/(a.first - a.second);
    // y = mx + c
    // c = y - mx
    double intercept = a.second - slope * a.first;
    return std::make_pair( slope, intercept );
  }
};

int main() {
  Square A( 2, 3, 3 ), B( 5, 6, 3 );
  A.getIntersectingLine( B );
  return 0;
}

/*
  Continuous Median:
  Numbers are randomly generated and passed to a method. Write a program to find and
  maintain the median value as new values are generated.
 */

#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::priority_queue;

class ContinousMedian {
  /*
    We maintain a constraint that maxHeap.size() >= minHeap;
    The size can vary by maximum 1.
  */
  priority_queue< double > maxHeap;
  priority_queue< double, std::vector<double>, std::greater<double> > minHeap;
  
public:
  void addRandom( double input ) {
    if( maxHeap.empty() ) {
      maxHeap.push( input );
      return;
    }

    if( maxHeap.size() == minHeap.size() ) {
      if( input > maxHeap.top() ) {
	minHeap.push( input );
	maxHeap.push( minHeap.top() );
	minHeap.pop();
      } else {
	maxHeap.push( input );
      }
    } else {
      // maxHeap.size() > minHeap()
      if( input > maxHeap.top() ) {
	minHeap.push( input );
      } else {
	maxHeap.push( input );
	minHeap.push( maxHeap.top() );
	maxHeap.pop();
      }
    }    
  }

  double getMedian() {
    if( maxHeap.empty() ) {
      return 0;
    }
    if( maxHeap.size() == minHeap.size() ) {
      return maxHeap.top();
    } else {
      return ( maxHeap.top() + minHeap.top() )/2.0;
    }
  }
};

int main() {
  ContinousMedian median;
  return 0;
}

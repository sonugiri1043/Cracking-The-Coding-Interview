/*
  Smallest K:
  Design an algorithm to find the smallest K numbers in an array.

  Solution:
  sorting, max heap, and selection rank.

  Max Heap:
  We first create a max heap (largest element at the top) for the first million numbers.
  Then, we traverse through the list. On each element, if it's smaller than the root, we
  insert it into the heap and delete the largest element (which will be the root). O( n logm )

  Selection Rank Algorithm (if elements are unique)
  Selection Rank is a well-known algorithm in computer science to find the ith smallest
  (or largest) element in an array in linear time. If the elements are unique, you can find
  the ith smallest element in expected O(n) time. The basic algorithm operates like this:
  1. Pick a random element in the array and use it as a "pivot", Partition elements around the
  pivot, keeping track of the number of elements on the left side of the partition.
  2. If there are exactly i elements on the left, then you just return the biggest element on the left.
  3. If the left side is bigger than i, repeat the algorithm on just the left part of the array.
  4. If the left side is smaller than i, repeat the algorithm on the right, but look for the element
  with rank i - leftSize.
 */

// g++ 14-Smallest-K-in-Array.cpp --std=c++11

#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

priority_queue<int> kSmallest( vector<int> input, int k ) {
  priority_queue<int> heap;
  for( auto v : input ) {
    if( heap.size() < k ) {
      heap.push( v );
    } else if( heap.top() < v ) {
      heap.push( v );
      heap.pop();
    }
  }
  return heap;
}

int main() {  
  return 0;
}

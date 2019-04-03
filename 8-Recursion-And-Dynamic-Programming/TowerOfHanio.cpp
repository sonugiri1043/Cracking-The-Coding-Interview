/*
  Towers of Hanoi:
  In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different
  sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending
  order of size from top to bottom ( i.e., each disk sits on top of an even larger one ).
  You have the following constraints:
  (1) Only one disk can be moved at a time.
  (2) A disk is slid off the top of one tower onto another tower.
  (3) A disk cannot be placed on top of a smaller disk.
  
  Write a program to move the disks from the first tower to the last using stacks.
 */

#include <iostream>

using std::cout;
using std::endl;

// Moves all disc from tower 1 to tower 3
void moveDisc( int noOfDisc, int srcTower, int bufferTower, int dstTower ) {
  if( noOfDisc <= 0 ) {
    return;
  }
  // move top n-1 from source to buffer, so buffer is new dst
  moveDisc( noOfDisc - 1, srcTower, dstTower, bufferTower );
  // move nth disc to destination
  cout<< "Moving disc " << noOfDisc << " from tower " << srcTower << " to tower " << dstTower << endl;
  // move n-1 discs from buffer to dest tower
  moveDisc( noOfDisc - 1, bufferTower, srcTower, dstTower );
}

int main() {
  int n = 5;
  // srcTower = 1
  // bufferTower = 2
  // dstTower = 3
  moveDisc( n, 1, 2, 3 );
}

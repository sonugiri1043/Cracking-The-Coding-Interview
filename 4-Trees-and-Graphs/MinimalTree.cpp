/*
  Given a sorted (increasing order) array with unique integer elements,
  write an algorithm to create a binary search tree with minimal height.
 */

#include <iostream>

using namespace std;

class Node {
public:
  int key;
  Node *left;
  Node *right;
};

Node * minimalTree( int arr[], int left, int right ) {
  /*
    The middle of each subsection of the array becomes the root
    of the node. The left half of the array will become our left
    subtree, and the right half of the array will become the right subtree.
  */

  Node *node = NULL;
  if( left <= right ) {
    int mid = ( left + right )/2; // Assume no overflow
    node = new Node();
    node->key = arr[ mid ];
    node->left = minimalTree( arr, left, mid - 1);
    node->right = minimalTree( arr, mid + 1, right );
  }
  return node;
}

int main() {
  int arr[ 10 ] = { 1, 2, 3, 5, 6, 8, 9, 12, 24, 30 };
  Node* root = minimalTree( arr, 0, 9 );
  return 0;
}

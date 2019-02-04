/*
  Implement a function to check if a binary tree is a binary search tree.
 */

#include<iostream>
#include<climits>

using namespace std;

class Node {
public:
  int key;
  Node *left;
  Node *right;
};

/* Solution #1: In-Order Traversal
   Copy the elements to an array, and then check to see if the array is sorted.
   This solution takes up a bit of extra memory, but it works if elements are unique.
*/

int pos = 0;
void copyBstToArray( Node *node, int arr[] ) {
  if( node == NULL )
    return;

  copyBstToArray( node->left, arr );
  arr[ pos ] = node->key;
  pos++;
  copyBstToArray( node->right, arr );
  return;
}

bool isValidBstV1( Node *node, int size ) {
  int *arr = new int[ size ];
  copyBstToArray( node, arr );
  for( int i=0; i < size - 1; i++ ) {
    if( arr[i] > arr[ i + 1 ] )
      return false;
  }
  return true;
}

/*
  Solution 2: Without using array
 */

int val = INT_MIN;
bool isValidBstV2( Node *node ) {
  if( node == NULL )
    return true;
  if( !isValidBstV2( node->left ) )
    return false;
  if( val != INT_MIN && node->key < val ) {
    return false;
  }
  if( !isValidBstV2( node->right ) )
    return false;
  return true; // All good
}

/*
  Solution 3: Using property "left <= current < right"
  all left nodes must be less than or equal to the current node,
  which must be less than all the right nodes.
 */
bool isValidBstV3( Node *node, int min, int max ) {
  if( node == NULL )
    return true;

  if( node->key < min || node->key > max ) {
    return false;
  }
  if( !isValidBstV3( node->left, min, node->key ) ) {
    return false;
  }

  if( !isValidBstV3( node->right, node->key, max ) ) {
    return false;
  }
  return true;
}

int main() {
  return 0;
}

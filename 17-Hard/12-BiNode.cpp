/*
  BiNode:
  Consider a simple data structure called BiNode, which has pointers to two other nodes. The
  data structure BiNode could be used to represent both a binary tree (where nodel is the left node
  and node2 is the right node) or a doubly linked list (where nodel is the previous node and node2
  is the next node). Implement a method to convert a binary search tree (implemented with BiNode)
  into a doubly linked list. The values should be kept in order and the operation should be performed
  in place (that is, on the original data structure).

  Example:
  Binary Search Tree:
               4 
             /   \
            /     \
           2       5
          / \       \
         1   3       6
	/   
       0
  Doubly Linked List:
  0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
*/

#include <iostream>

using std::cout;
using std::endl;

struct Node {
  int key;
  Node *left;
  Node *right;
  Node *next;
  Node *prev;
 
  Node( int key_ ) {
    key = key_;
    left = NULL;
    right = NULL;

    next = NULL;
    prev = NULL;
  }
};

void bstToDll( Node *node, Node *head, Node *tail ) {
  if( node->left ) {
    bstToDll( node->left, head, node );
  }
  if( node->right ) {
    bstToDll( node->right, node, tail );
  }
  if( node->left == NULL ) {
    head->next = node;
    node->prev = head;
  }
  if( node->right == NULL ) {
    node->next = tail;
    tail->prev = node;
  }
}

void traverseDoublyLinkedList( Node *head, Node *tail ) {
  Node *node = head->next;
  while( node->next != NULL ) {
    cout<< node->key << "->";
    node = node->next;
  }
  cout<< endl;
}

int main() {
  Node *root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->right->right = new Node(6);

  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->left->left->left = new Node(0);

  Node *head = new Node(-1);
  Node *tail = new Node(-1);
  bstToDll( root, head, tail );
  traverseDoublyLinkedList( head, tail );
  return 0;
}

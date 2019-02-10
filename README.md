# Chapter 1: Arrays and Strings

1.  **Is Unique**: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
2.  **Check Permutation**: Given two strings, write a method to decide if one is a permutation of the other.
3.  **URLify**: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
4.  **Palindrome Permutation**: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
5.  **One Away**: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
6.  **String Compression**: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).
7.  **Rotate Matrix**: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. can you do this in place?
8.  **Zero Matrix**: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.
9.  **String Rotation**: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, S1 and S2, write code to check if S2 is a rotation of S1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").


# Chapter 2: Linked Lists

1.  **Remove Dups**: Write code to remove duplicates from an unsorted linked list.
    How would you solve this problem if a temporary buffer is not allowed?
2.  **Return Kth to Last**: Implement an algorithm to find the kth to last element of a singly linked list.
3.  **Delete Middle Node**: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
4.  **Partition**: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. lf x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
5.  **Sum Lists**: You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
6.  **Palindrome**: Implement a function to check if a linked list is a palindrome.
7.  **Intersection**: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
8.  **Loop Detection**: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop. DEFINITION Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.

# Chapter 3: Stacks and Queues

1.  **Three in One**: Describe how you could use a single array to implement three stacks.
2.  **Stack Min**: How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.
3.  **Stack of Plates**: Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop ( ) should return the same values as it would if there were just a single stack).
4.  **Queue via Stacks**: Implement a MyQueue class which implements a queue using two stacks.
5.  **Sort Stack**: Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty.
6.  **Animal Shelter**: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linked List data structure.

# Chapter 4: Trees and Graph

1.  **Route Between Nodes**: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
2.  **Minimal Tree**: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
3.  **List of Depths**: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth 0, you'll have 0 linked lists).
4.  **Check Balanced**: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
5.  **Validate BST**: Implement a function to check if a binary tree is a binary search tree.
6.  **Successor**: Write an algorithm to find the "next" node (i .e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.
7.  **Build Order**: You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first project). All of a project's dependencies must be built before the project is. Find a build order that will allow the projects to be built. If there is no valid build order, return an error.
    EXAMPLE
    Input:
    projects: a, b, c, d, e, f
    dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
    Output: f, e, a, b, d, c
8.  **First Common Ancestor**: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
9.  **BST Sequences**: A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.
10.  **Check Subtree**: T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1. A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
11.  **Random Node**: You are implementing a binary tree class from scratch which, in addition to insert, find, and delete, has a method getRandomNode() which returns a random node from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm for getRandomNode, and explain how you would implement the rest of the methods.
12.  **Paths with Sum**: You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

# Chapter 5: Bit Manipulation
1.  **Insertion**: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
    EXAMPLE
    Input: N = 10000000000, M = 10011, i = 2, j = 6
    Output: N 10001001100
2.  **Binary to String**: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:"
3.  **Flip Bit to Win**: You have an integer and you can flip exactly one bit from a 13 to a 1. Write code to find the length of the longest sequence of ls you could create.
    EXAMPLE
    Input: 1775  ( or: 1113111131111 )
    Output: 8
4.  **Next Number**: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.
5.  **Debugger**: Explain what the following code does: ( (n & (n -1) ) e) .
6.  **Conversion**: Write a function to determine the number of bits you would need to flip to convert integer A to integer B.
    EXAMPLE
    Input: 29 ( or: 111101 ), 15 ( or: 01111)
    Output: 2
7.  **Pairwise Swap**: Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
8.  **Draw Line**: A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (x1, y) to (x2, y) . 
    The method signature should look something like:
    drawLine( byte[] screen, int width, int x1, int x2, int y )

# Chapter 12: C and C++

1.  **Last K Lines**: Write a method to print the last K lines of an input file using C++.
2.  **Reverse String**: Implement a function void reverse( char* str) in C or C++ which reverses a null-terminated string.
3.  **Hash Table vs. STL Map**: Compare and contrast a hash table and an STL map. How is a hash table implemented? If the number of inputs is small, which data structure options can be used instead of a hash table?
4.  **Virtual Functions**: How do virtual functions work in (++?
5.  **Shallow vs. Deep Copy**: What is the difference between deep copy and shallow copy? Explain how you would use each.
6.  **Volatile**: What is the significance of the keyword "volatile" in C?
7.  **Virtual Base Class**: Why does a destructor in base class need to be declared virtual?
8.  **Copy Node**: Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure. The Node data structure contains two pointers to other Nodes.
9.  **Smart Pointe**r: Write a smart pointer class. A smart pointer is a data type, usually implemented with templates, that simulates a pointer while also providing automatic garbage collection. It automatically counts the number of references to a SmartPointer<T* > object and frees the object of type T when the reference count hits zero.
10.  **Malloc**: Write an aligned malloc and free function that supports allocating memory such that the memory address returned is divisible by a specific power of two. EXAMPLE align_malloc (1000 ,128) will return a memory address that is a multiple of 128 and that points to memory of size 1000 bytes. aligned_free () will free memory allocated by align_malloc.
11.  **2D Alloc**: Write a function in C called my2DAlloe which allocates a two-dimensional array. Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr[i][j].

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

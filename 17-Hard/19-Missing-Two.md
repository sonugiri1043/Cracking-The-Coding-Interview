## Missing Two:
  You are given an array with all the numbers from 1 to N appearing exactly once, except
  for one number that is missing. How can you find the missing number in O(N) time and
  O(1) space? What if there were two numbers missing?

## Solution 1:
  When 1 number is missing.
  Get the sum n*(n-1)/2 and subtract each element in array from this. you would get the 
  missing number.

  When 2 numbers are missing.
  Get the sum which will give x + y = n.
  Get the product which will give x*y = n where n is known. Use quadratic to find x and y.

## Solution 2:
  To find 1 missing number
  - 1. XOR all the array elements, let the result of XOR be X1.
  - 2. XOR all numbers from 1 to n, let XOR be X2.
  - 3. XOR of X1 and X2 gives the missing number.

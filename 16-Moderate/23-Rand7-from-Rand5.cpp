/*
  Rand7 from Rand5:
  Implement a method rand7() given rand5(). That is, given a method that generates a
  random number between 0 and 4 (inclusive), write a method that generates a random
  number between 0 and 6 (inclusive).

  7 can be represented in a sequence of 3 bits

  Use rand(5) to randomly fill each bit with 0 or 1.
  For e.g: call rand(5) and

  if the result is 1 or 2, fill the bit with 0
  if the result is 4 or 5, fill the bit with 1
  if the result is 3 , then ignore and do it again (rejection)

  This way we can fill 3 bits randomly with 0/1 and thus get a number from 1-7.
 */

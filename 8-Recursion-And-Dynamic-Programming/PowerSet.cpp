/*                                                                                                                                           
  Power Set: Write a method to return all subsets of a set.                                                                                  
                                                                                                                                             
  Solution:                                                                                                                                  
  When we generate a subset, each element has the "choice" of either being in there                                                          
  or not. So doing { 2 * 2 * 2 ... } n times gives us 2^n subsets.                                                                           
                                                                                                                                             
  There are 2^n subsets and each of n elements will be contained in half of the subsets                                                      
  ( which is 2^n-1 ). Therefore, the total nuber of elements across all of those                                                             
  subsets is n * 2^(n-1).                                                                                                                    
                                                                                                                                             
  Space/Time complexity: O( n2^n ).                                                                                                          
*/



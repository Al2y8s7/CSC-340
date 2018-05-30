** CSC 340 - Programming Methodology **

Author: Alvin Nguyen


* This program contains 3 functions: isPalidrome, digitSum, and waysToClimb.

** isPalindrome(const string& input) takes a single parameter. This function takes a string and returns true if that string is a palindrome. 

i.e tacocat is a palindrome as is it read from left to right was taco cat and right to left as taco cat as well.


** digitSum(int input) takes a single parameter.  This function takes an integer and returns the sum of its digits.  

i.e. Input = 123, Sum of 123 = 6 (1+2+3)


** waysToClimb(int numStairs) takes a single parameter.  This function takes an integer as the total number of steps for the staircase and returns the number of ways to climb it.

i.e. numStairs = 4, ways to climb staircase = 5
    
    Possible combinations:
      -> 1 step, 1 step, 1 step, 1 step
      -> 1 step, 1 step, 2 steps
      -> 2 steps, 2 steps
      -> 2 steps, 1 step, 1 step
      -> 1 step, 2 steps, 1 step


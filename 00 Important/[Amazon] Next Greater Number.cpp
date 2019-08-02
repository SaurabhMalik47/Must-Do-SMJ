/*
Problem:

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers. 
If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

                                                      OR

Given a number n, find the smallest number that has same set of digits as n and is greater than n.
If n is the greatest possible number with its set of digits, then print “not possible”.

Input:
6
1 2 3 6 5 4

Output:
1 2 4 3 5 6

Examples:

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"


/****************************************************** Hint *****************************************************/

1) If all digits are sorted in descending order, then output is always “Not Possible”. For example, 4321.
2) If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234.
3) For other cases, we need to process the number from rightmost side (Because we need to find the smallest of all greater numbers)

/****************************************************** Approach *****************************************************/

I) Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously
   traversed digit. For example, if the input number is “534976”, we stop at 4 because 4 is smaller than next digit 9.
   If we do not find such a digit, then output is “Not Possible”.

II) Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’.
    For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.

III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to ‘d’ to the end of number. The number that we get after sorting is the output. 
    For above example, we sort digits in bold 536974. We get “536479” which is the next greater number for input 534976.

/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/


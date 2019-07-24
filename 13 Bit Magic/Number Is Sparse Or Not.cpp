/*
Problem:
Given a number N, check whether it is sparse or not. 
A number is said to be a sparse number if in the binary representation of the number no two or more consecutive bits are set.

Input:
2
3

Output:
1
0

Explanation:
Testcase 1: Binary Representation of 2 is 10, which is not having consecutive set bits. So, it is sparse number.
Testcase 2: Binary Representation of 3 is 11, which is having consecutive set bits in it. So, it is not a sparse number.



/****************************** Time Complexity : O(1) and Space Complexity : O(1) ******************************/
bool isSparse(int n)
{
    if(n & (n>>1))
      return 0;
    else
      return 1;
}

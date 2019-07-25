/*
Problem:
Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. 
Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
If no equilibrium point exists print -1.

Input:
1
1
5
1 3 5 2 2

Output:
1
3

Explanation:
Testcase 1: Since its the only element hence its the only equilibrium point.
Testcase 2: For second test case equilibrium point is at position 3 as elements below it (1+3) = elements after it (2+2).


/****************************** Time Complexity : O(n^2) and Space Complexity : O(n) ******************************/

int EquilibriumPosition(int a[], int n)
{
    int sum = 0;            // Total Sum
    for(int i=0; i<n; i++)
        sum += a[i];
        
    int left_sum = 0;       // Left Sum
    
    for(int i=0; i<n; i++)
    {
        sum = sum - a[i];      //Total Sum Became Right Sum
        if(sum == left_sum)
          return i+1;
        else
          left_sum += a[i];
    }
    return -1;
}

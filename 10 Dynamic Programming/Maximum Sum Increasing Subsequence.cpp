/*
Problem:
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10
*/


/****************************** Time Complexity : O(n^2) and Space Complexity : O(n) ******************************/

int maxSumIncreasingSubsequence(int a[], int n)
{
    int* dp = new int[n];
    for(int i=0; i<n; i++)
       dp[i] = a[i];
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i] > a[j]  && dp[i] < dp[j]+a[i])
                dp[i] = dp[j]+a[i];
        }
    }
    
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] > max)
          max = dp[i];
    }
      
    return max;
}

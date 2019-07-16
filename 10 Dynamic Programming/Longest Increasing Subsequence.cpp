/* 
Problem:
Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence.
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements 
are in sorted order, lowest to highest, and in which the subsequence is as long as possible. 
This subsequence is not necessarily contiguous, or unique.

Input:
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3
*/

/****************************** Time Complexity : O(n^2) and Space Complexity : O(n) ******************************/
int findLIS(int a[], int n)
{
    int dp[n];
    for(int i=0; i<n; i++)
      dp[i] = 1;
      
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i] > a[j])
              dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    int maxLength = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] > maxLength)
          maxLength = dp[i];
    }
    return maxLength;
}

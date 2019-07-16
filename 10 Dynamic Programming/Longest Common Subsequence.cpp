/*
Problem:
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2
*/


/*
1.) if( i==0 || j==0)
    dp[i][j]=0;
2.) if(s1[i-1] == s2[j-1])
    dp[i][j]=dp[i-1][j-1] + 1;
3.) else
    dp[i][j]= max( dp[i-1][j] ,dp[i][j-1] );
*/


/****************************** Time Complexity : O(m*n) and Space Complexity : O(m*n) ******************************/
int LongestCommonSubsequence(string s1, string s2, int m, int n)
{
   int dp[m+1][n+1];

   for(int i=0; i<=m; i++)
   {
     for(int j=0; j<=n; j++)
     {
        if(i == 0 || j == 0)
          dp[i][j] = 0;
          
        else if(s1[i-1] == s2[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
          
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
    return dp[m][n];
}

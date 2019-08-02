/*
Problem:
Given two strings X and Y. The task is to find the length of the longest common substring.
Input:
6 6
ABCDGH
ACDGHR
3 2
ABC
AC
Output:
4
1
*/


/******************************************************* Hint *********************************************************/

Dynamic Programming can be used to find the longest common substring in O(m*n) time. 

The idea is to find length of the longest common suffix for all substrings of both strings and store these lengths in a table.

1.) if( i == 0 || j == 0)
      X[i]Y[j] = 0 ;
2.) if (X[i-1] == Y[j-1])
       X[i]Y[j] = X[i-1]Y[j-1] + 1 ;
3.) else 
       X[i]Y[j] = 0 ;


/****************************** Time Complexity : O(m*n) and Space Complexity : O(m*n) ******************************/

int LongestCommonString(string s1, string s2, int m, int n)
{
   int dp[m+1][n+1];
   int ans = 0;
   
   for(int i=0; i<=m; i++)
   {
     for(int j=0; j<=n; j++)
     {
        if(i == 0 || j == 0)
          dp[i][j] = 0;
          
        else if(s1[i-1] == s2[j-1])
        {
          dp[i][j] = dp[i-1][j-1] + 1;
          ans = max(ans, dp[i][j]);
        }
          
        else
          dp[i][j] = 0;    
      }
    }
    return ans;
}

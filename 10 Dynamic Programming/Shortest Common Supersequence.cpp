/*
Problem:
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
abcd xycd
efgh jghi

Output:
6
6


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


int ShortestCommonSupersequence(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    
    int len = LongestCommonSubsequence(s1, s2, m, n);
    
    return (m + n) - len;
}

/*Problem:
Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

1. Insert
2. Remove
3. Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
4 5
geek gesek

Output:
1


/****************************** Time Complexity : O(n^2) and Space Complexity : O(n) ******************************/
int EditDistance(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1];   
    for(int i=0; i<=m; i++)
      dp[i][0] = i;
    for(int j=0; j<=n; j++)
      dp[0][j] = j;
           
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1] == s2[j-1])
              dp[i][j] = dp[i-1][j-1];
            else
              dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}

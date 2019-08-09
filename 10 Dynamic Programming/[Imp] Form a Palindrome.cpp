/*
Problem:
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:
abcd
aba
geeks

Output:
3
0
3

/*********************************************** Approach / Hint ************************************************/

The problem of finding minimum insertions can also be solved using Longest Common Subsequence (LCS) Problem. 
If we find out LCS of string and its reverse, we know how many maximum characters can form a palindrome. 
We need insert remaining characters. Following are the steps.
1) Find the length of LCS of input string and its reverse. Let the length be ‘len’.
2) The minimum number insertions needed is length of input(n) string minus ‘len’.

/**************************** Time Complexity : O(n^2) and Space Complexity : O(n^2) ****************************/

int LCS(string s1 ,string s2 , int m , int n)  // Longest Common Subsequence 
{
    int dp[m+1][n+1];
    
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n ;j++)
        {
            if(i==0 || j==0)
             dp[i][j] = 0 ;
             
            else if( s1[i-1] == s2[j-1])
             dp[i][j] = dp[i-1][j-1] + 1;
             
            else
             dp[i][j] = max( dp[i][j-1], dp[i-1][j] );            
        }
    }
    return dp[m][n];
}

int Form_Palindrome(string s , int n)
{   
    string rev = s;
    reverse(rev.begin(), rev.end());  //Reverse The String
    
    int len = LCS( s, rev, n, n);
    
    return ( n - len );
}

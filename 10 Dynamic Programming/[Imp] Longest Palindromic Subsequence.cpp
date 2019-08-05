/*
Problem:
Given a sequence, find the length of the longest palindromic subsequence in it.

Input:
geeksforgeeks
adbgcfbea
adbbca

Output:
5
5
4

Explaination:
Testcase 1 : "eekee", "eesee", etc. are Longest Palindromic Subsequence with Length = 5.
Testcase 2 : "abgba" is the Longest Palindromic Subsequence with Length = 5.
Testcase 3 : "abba" is the Longest Palindromic Subsequence with Length = 4.

/******************************************************* Hint *******************************************************/

// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 

/****************************** Time Complexity : O(n^2) and Space Complexity : O(n^2) ******************************/

int LongestPalindromicSubsequence(string s)
{
    int n = s.length();
    int dp[n][n];
    int i, j, k;
    
    // Fill all Diagonal Cells of Matrix as 1
    for(i=0; i<n; i++)
        dp[i][i] = 1;
        
    // Now, Check for Each Cell above Diagonal
    for(int k=2; k<=n; k++)
    {
        for(i=0; i<n-k+1; i++)
        {
            j = i + k - 1;
            if(k==2 && s[i] == s[j])
                dp[i][j] = 2;
            else if(s[i] == s[j])
                 dp[i][j] = 2 + dp[i+1][j-1];
            else
                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

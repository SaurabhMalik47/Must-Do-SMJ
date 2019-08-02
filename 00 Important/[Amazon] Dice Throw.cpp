/*
Problem:
Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X.
X is the summation of values on each face when all the dice are thrown.

Input: 
6 3 12
10 8 25

Output:
25
318648


/****************************** Time Complexity : O(n*s) and Space Complexity : O(n*s) ******************************/

long DiceThrow(int m, int n, int s) 
{ 
    long dp[n+1][s+1]; 

    memset(dp, 0, sizeof(dp)); 

    dp[0][0] = 1; 
 
    for (int i=1; i<=n; i++)           // Iterate over dices 
    {  
        for (int j=i; j<=s; j++)      // Iterate over sum 
        { 
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
 
            if(j-m-1 >= 0) 
                dp[i][j] -= dp[i - 1][j-m-1]; 
        } 
    } 
    return dp[n][s]; 
} 

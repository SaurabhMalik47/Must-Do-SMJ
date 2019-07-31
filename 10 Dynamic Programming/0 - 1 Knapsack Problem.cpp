/*
Problem:
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items 
respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that 
sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Input:
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
The third line consists of N space separated positive integers denoting the values of the N items.
The fourth line consists of N space separated positive integers denoting the weights of the corresponding items.

3
4
1 2 3
4 5 1

Output:
3


/****************************** Time Complexity : O(n^2) and Space Complexity : O(n*capacity) ******************************/
int knapsack(int n, int capacity, int* v, int* w)
{
    int dp[n+1][capacity+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=capacity; j++)
        {
            if(i == 0 || j == 0) 
               dp[i][j] = 0;
            else if(w[i-1] > j)
               dp[i][j] = dp[i-1][j];
            else
               dp[i][j] = max(dp[i-1][j-w[i-1]] + v[i-1],  dp[i-1][j]);
        }
    }
    return dp[n][capacity];    
}

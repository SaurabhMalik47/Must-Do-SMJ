/*
Problem:
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of 
S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. 
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

For Input, the first line contains an integer denoting the size of array. The second line contains integers denoting 
the elements of the array. The third line contains an integer 'N' denoting the cents.

Input:
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5
*/


/****************************** Time Complexity : O(n^2) and Space Complexity : O(n) ******************************/
int CoinChange(int a[], int n, int amount)
{
    int dp[amount+1] = {0};
    dp[0]=1;

    for(int i=0; i<n; i++)        
    {
        for(int j=1; j<=amount; j++)
        {
          if(j >= coins[i])      
             dp[j] += dp[j-coins[i]] ;
        }
    }
    return dp[amount];
}

/*
Problem:
Find Binomial Coefficient C(n, r) --OR-- nCr for given n and r. Modulus your output to 10^9 + 7.

Input:
3 2
4 2

Output:
3
6


/****************************** Time Complexity : O(n*r) and Space Complexity : O(n*r) ******************************/
int BinomialCoefficient(int n, int r)
{
    if(n < r)
      return 0;

    int dp[n+1][r+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=r; j++)
        {
            if(i==j || j==0)
              dp[i][j] = 1;
            else
              dp[i][j] = ( (dp[i-1][j-1]) + (dp[i-1][j]) ) % 1000000007;
        }
    }
    return dp[n][r];
}

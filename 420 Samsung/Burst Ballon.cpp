**********************************Burst Ballon**************************************

#include <bits/stdc++.h>
using namespace std;

int maxCoins(int A[], int n) 
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int len=1; len<=n; len++)
    {
        for(int i=0; i<=n-len; i++)
        {
            int j=i+len-1;
            for(int k=i; k<=j; k++)
            {
                int lvalue = 1, rvalue = 1;
                if(i != 0)
                    lvalue = A[i-1];
                if(j != n-1)
                    rvalue = A[j+1];
                int before = 0, after = 0;
                if(i != k)
                    before = dp[i][k-1];
                if(j != k)
                    after = dp[k+1][j];

                dp[i][j] = max(lvalue*A[k]*rvalue + before+after, dp[i][j]);
            }
        }
    }
    return dp[0][n-1];
    
}

int main()
{
    int arr[] = {3, 1, 5, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxCoins(arr, n);
    return 0;
}

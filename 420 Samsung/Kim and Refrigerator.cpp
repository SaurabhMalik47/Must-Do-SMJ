**********************Kim and Refrigerator********************

#include <bits/stdc++.h>
using namespace std;
int dp[12][1 << 11]; // bit mask with max 12 bits
int x[12], y[12],n; // 5<= N <= 10 , home, office
int calc(int p, int mask) 
{
    if(p == 0 && mask == 0) 
        return 0; 
    else if(p == 0) 
        return 1e9;
    dp[p][mask]=1e9;
    for (int i = n; i >=0 ; --i) 
    {
        if (mask & (1 << i)) 
        {
            int dist = abs(x[p] - x[i]) + abs(y[p] - y[i]);
            dp[p][mask] = min( dp[p][mask], calc(i, mask ^ (1 << i)) + dist);
        }
    }
    return dp[p][mask];
}
int main() 
{
 std::ios::sync_with_stdio(false);
 for (int i = 1; i <= 10; ++i) 
 {
 cin>>n;
 cin>>x[0]>>y[0];
 cin>>x[n+1]>>y[n+1];
 for (int j = 1; j <= n; ++j) 
 {
 cin>>x[j]>>y[j];
 }
 memset(dp, -1, sizeof dp);
 int mask = (1 << (n + 1)) - 1;
 cout<<"Case #"<< i <<": "<< calc(n + 1, mask)<<endl;
 break;
 }
 return 0;
}


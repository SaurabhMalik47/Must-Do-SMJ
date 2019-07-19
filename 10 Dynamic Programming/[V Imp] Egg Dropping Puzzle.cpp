/*
Problem:
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break.
You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the 
best strategy. There are few rules given below:
• An egg that survives a fall can be used again.
• A broken egg must be discarded.
• The effect of a fall is the same for all eggs.
• If the egg doesn't break at a certain floor, it will not break at any floor below.
• If the eggs breaks at a certain floor, it will break at any floor above.

Input:
2 10    // n=2, k=10
3 5     // n=3, k=5

Output:
4
3


/****************************** Time Complexity : O(nk^2) and Space Complexity : O(n*k) ******************************/
int EggDropping(int n, int k)
{
    int dp[n+1][k+1];
    int i, j, x, ans;
    for(i=1; i<=n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
	  for(j=1; j<=k; j++) 
		  dp[1][j] = j; 

	  for(i=2; i<=n; i++) 
	  { 
		for(j=2; j<=k; j++) 
		{ 
			dp[i][j] = INT_MAX; 
			for(x=1; x<=j; x++) 
			{ 
				ans = 1 + max(dp[i-1][x-1], dp[i][j-x]); 
				dp[i][j] = min(dp[i][j], ans); 
			} 
		} 
	} 
	return dp[n][k];
}


/****************************** Time Complexity : O(n*logk) and Space Complexity : O(n*k) ******************************/

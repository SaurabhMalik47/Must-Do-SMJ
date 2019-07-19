/*
Problem:
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the 
cut length of a line segment each time is integer either x, y or z.and after performing all cutting operation
the total number of cutted segments must be maximum. 

Input:
4         // N
2 1 1     // x, y, z
5
5 3 2

Output:
4
2

Explaination:
In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.
In second test case, we can make two segments of lengths 3 and 2.

/****************************** Time Complexity : O(n) and Space Complexity : O(n) ******************************/
int MaximumCuttedSegments(int n, int x, int y, int z)
{
    int dp[n+1];
    dp[0] = 0;
    int i;
    for(i=1; i<=n; i++)
      dp[i] = -1;
            
    for(i=0; i<n; i++)
    {
        if(dp[i] != -1)
        {
            if(i+x <= n)
		dp[i+x] = max(dp[i]+1, dp[i+x]);
	    if(i+y <= n)
		dp[i+y] = max(dp[i]+1, dp[i+y]);
	    if(i+z <= n)    
		dp[i+z] = max(dp[i]+1, dp[i+z]);
        }
    }
    return dp[n];
}

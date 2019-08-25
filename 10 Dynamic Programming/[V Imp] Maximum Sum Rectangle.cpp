/*
Problem:
Given a 2D array, find the maximum sum subarray in it.

Input: 
Row = 4, Column = 5
 1   2  -1 -4 -20 
-8  -3   4  2   1 
 3   8  10  1   3 
-4  -1   1  7  -6

Ouptut:
29

/****************************** Time Complexity : O(col*col*row) and Space Complexity : O(row) ******************************/

int KadaneAlgorithm(int a[], int n)
{
	int current_sum = 0, max_sum = a[0];

	for(int i=0; i<n; i++)
	{
	    current_sum += a[i];
	    
	    if(current_sum >= max_sum)
	       max_sum = current_sum;
	       
	    if(current_sum < 0)
	       current_sum = 0;
	}
	return max_sum;
}




int main()
{
    int m, n, ans = INT_MIN;
    int i, j, k, l, r;
    cin >> m >> n;
    int a[m][n];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            cin >> a[i][j];
        
    }
        
    int temp[m];
    for(l=0; l<n; l++)
    {
        memset(temp, 0, sizeof(temp));
        for(r=l; r<n; r++)
        {
            for(i=0; i<m; i++)
                temp[i] += a[i][r];
            ans = max(ans, KadaneAlgorithm(temp, m));
        }
    }
    cout<<ans<<endl;
}

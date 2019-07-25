/*
Problem:
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
5
1 2 3 -2 5
4
-1 -2 -3 -4

Output:
9
-1


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

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

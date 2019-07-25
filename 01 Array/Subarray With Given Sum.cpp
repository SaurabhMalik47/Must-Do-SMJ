/*
Problem:
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10

Output:
2 4
1 5

Note:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring 
subarray from the left if sum equals to subarray, else print -1.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

void FindSubArray(int a[], int n, int sum)
{
    bool found = false;
    int current_sum = 0, start = 0;
    for(int i=0; i<n; i++)
    {
        current_sum += a[i];
        while(current_sum>sum && start<=i)
        {
            current_sum -= a[start];
            start++;
        }
        if(current_sum == sum)
        {
           found = true;
           cout << start+1 << " " << i+1 ;
           break;
        }
    }
    if(found == false)
       cout << "-1";
}

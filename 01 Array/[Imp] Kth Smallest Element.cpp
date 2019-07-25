/*
Problem:
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element 
in the given array. It is given that all array elements are distinct.

Input:
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:
7
15


/****************************** Time Complexity : O(n + klogn) and Space Complexity : O(1) ******************************/

int KthSmallestElement(int *a, int n, int k)
{
    priority_queue<int, vector<int>, greater <int> > pq;           //Min Heap
    
    for(int i=0; i<n; i++)
        pq.push(a[i]);
        
    for(int i=0; i<k-1; i++)
        pq.pop();
        
    return pq.top();
}

/*
Problem:
Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. 
Compute how much water can be trapped in between blocks after raining.
Structure is like below:
| |
|_|
We can trap 2 units of water in the middle gap.

Input:
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

int TrapWater(int a[], int n) 
{ 
    int water = 0; 
    int left_max = 0, right_max = 0; 

    int lo = 0, hi = n-1; 
      
    while(lo <= hi)  
    { 
        if(a[lo] < a[hi]) 
        { 
            if(a[lo] > left_max) 
               left_max = a[lo]; 
            else
               water += left_max - a[lo]; 
               
            lo++; 
        } 
        else
        { 
            if(a[hi] > right_max) 
               right_max = a[hi]; 
            else
               water += right_max - a[hi]; 
               
            hi--; 
        } 
    } 
    return water; 
} 


/****************************** Time Complexity : O(n) and Space Complexity : O(n) ******************************/

int TrapWater(int a[], int n)
{
    int left[n]; 
    int right[n]; 
    int water = 0;   
   
    left[0] = a[0];                                // Fill left array 
    for (int i=1; i<n; i++) 
       left[i] = max(left[i-1], a[i]); 
  
    right[n-1] = a[n-1];                           // Fill right array 
    for (int i=n-2; i>=0; i--) 
       right[i] = max(right[i+1], a[i]); 
    
    for (int i=0; i<n; i++) 
       water += min(left[i], right[i]) - a[i]; 
  
    return water; 
}

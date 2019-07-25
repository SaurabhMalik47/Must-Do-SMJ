/*
Problem:
Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size m and n. 
The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

Note: Expected time complexity is O((m+n) log(m+n)). DO NOT use extra space. We need to modify existing arrays as following.
Input: arr1[] = {1, 5, 9, 10, 15, 20};
       arr2[] = {2, 3, 8, 13};
Output: arr1[] = {1, 2, 3, 5, 8, 9}
        arr2[] = {10, 13, 15, 20} 
        
Input:
4 5
1 3 5 7
0 2 6 8 9

Output:
0 1 2 3 5 6 7 8 9


/****************************** Time Complexity : O(n1+n2) and Space Complexity : O(1) ******************************/

void mergeSortedArrays(int a1[], int a2[], int n1, int n2)
{
   int i = 0, j = 0;
   for(int k=0; k<n1+n2; k++)
   {
	  if(i<n1 && j<n2)
	  {
	    if(a1[i] <= a2[j])
	    {
	       cout << a1[i] << " ";
	       i++;
	    }
	    else if(a1[i] > a2[j])
	    {
	      cout << a2[j] << " ";
	      j++;
	    }
	  }
	  else if(i < n1)
	  {
	     cout << a1[i] << " ";
	     i++;
	  }
	  else if(j < n2)
	  {
	     cout << a2[j] << " ";
	     j++;
	  }
   }
}

/****************************** Time Complexity : O(n1+n2) and Space Complexity : O(n1+n2) ******************************/

void MergeTwoSortedArrays(int a1[], int a2[], int n1, int n2)
{ 
    int i = 0, j = 0, k = 0; 
    int a3[n1+n2];
    
    // Traverse Both Arrays 
    while (i<n1 && j<n2) 
    { 
        if (a1[i] < a2[j]) 
            a3[k++] = a1[i++]; 
        else
            a3[k++] = a2[j++]; 
    } 
  
    // Store Remaining Elements of First Array 
    while (i < n1) 
        a3[k++] = a1[i++]; 
  
    // Store Remaining Elements of Second Array 
    while (j < n2) 
        a3[k++] = a2[j++]; 
        
    for(k=0; k<n1+n2; k++)
      cout << a3[k] << " ";
} 

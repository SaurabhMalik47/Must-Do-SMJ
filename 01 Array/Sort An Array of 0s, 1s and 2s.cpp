/*
Problem:
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input :
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

void Sort0s1s2s(int a[], int n)
{
     int count0 = 0, count1 = 0, count2 = 0;
     int i;
     for(i=0; i<n; i++)
     {
         if(a[i] == 0)
           count0++;
         else if(a[i] == 1)
           count1++;
         else
           count2++;
     }
     
     i=0;
     while(count0-- && i<n)
           a[i++] = 0;
     while(count1-- && i<n)
           a[i++] = 1;
     while(count2-- && i<n)
           a[i++] = 2;
       
     for(i=0; i<n; i++)
        cout << a[i] << " ";
}

/*
Problem:
Given arrival and departure times of all trains that reach a railway station. Your task is to find the 
minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day.
Also, arrival and departure times will not be same for a train, but we can have
arrival time of one train equal to departure of the other.

In such cases, we need different platforms, i.e at any given instance of time, 
same platform can not be used for both departure of a train and arrival of another.

Input:
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 

Output:
3
1


/****************************** Time Complexity : O(n*logn) and Space Complexity : O(1) ******************************/

int MinimumPlatforms(int a[], int d[], int n)
{
    sort(a, a+n);
    sort(d, d+n);
    
    int plat_needed = 1, ans = 1;  // plat_needed indicates number of platforms needed at a time 
    int i = 1, j = 0;
    
    while(i<n && j<n)
    {
        if(a[i] < d[j])
        {
            plat_needed++;
            i++; 
            
            if(plat_needed > ans)
              ans = plat_needed;
        }
        
        
        else
        {
           plat_needed--;
           j++;
        }
    }
    return ans;
}

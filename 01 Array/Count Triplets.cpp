/*
Problem:
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

Input:
4
1 5 3 2
3
3 2 7

Output:
2
-1


/****************************** Time Complexity : O(n^2) and Space Complexity : O(1) ******************************/

void CountTriplets(int a[], int n)
{
    sort(a, a+n);
    int count = 0;
    for(int i=n-1; i>=0; i--)
    {
        int j = 0;
        int k = i-1;
        while(j < k)
        {
            if(a[i] == a[j]+a[k])
            {
                count++;
                j++;
                k--;
            }
            else if(a[i] > a[j]+a[k])
                 j++;
            else
                 k--;
        }
    }
    
    if(count == 0)
      cout << "-1" << endl;
    else
      cout << count << endl;
}

/*
Problem:
The cost of stock on each day is given in an array A[] of size N.
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input:
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/

void StockBSMaximumProfit(int *a, int n)
{
    int start = 0, end = 0;
    int max = a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i] > a[start] && a[i] > max)
        {
           max = a[i];
           end = i;
        }
        else
        {
            if(end > start)
              cout << start << " " << end << " " ;
                
            start = i;
            max = a[start]; 
        }
    }
    if(end == n-1)
       cout<< start <<" "<< end << " ";
}

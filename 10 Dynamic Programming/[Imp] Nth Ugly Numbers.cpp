/*
Problem:
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. By convention, 1 is included. Write a program to find Nth Ugly Number.
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.

Input:
10
4

Output:
12
4



/****************************** Time Complexity : O(n) and Space Complexity : O(n) ******************************/
int FindNthUglyNumber(int n)
{
    int ugly[n];
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
    int next_ugly_number = 1;
    
    ugly[0] = 1;
    for(int i=1; i<n; i++)
    {
        next_ugly_number = min( next_multiple_of_2,  min(next_multiple_of_3,  next_multiple_of_5) );
        ugly[i] = next_ugly_number;
        
        if(next_ugly_number == next_multiple_of_2)
        {
            i2++;
            next_multiple_of_2 = ugly[i2]*2;
        }
        
        if(next_ugly_number == next_multiple_of_3)
        {
            i3++;
            next_multiple_of_3 = ugly[i3]*3;
        }
        
        if(next_ugly_number == next_multiple_of_5)
        {
            i5++;
            next_multiple_of_5 = ugly[i5]*5;
        }
    }
    return ugly[n-1];
}

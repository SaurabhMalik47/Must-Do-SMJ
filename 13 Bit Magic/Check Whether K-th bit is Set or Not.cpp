/*
Problem:
Given a number N and a bit number K, check if Kth bit of N is set or not. A bit is called set if it is 1.
Position of set bit '1' should be indexed starting with 0 from RSB side in binary representation of the number.

Input:
4       //n
0       //k
4
2
500
3

Output:
No
Yes
No

Hint : Use Left Shift Operator / Right Shift Operator


/****************************** Time Complexity : O(k) and Space Complexity : O(1) ******************************/
void isKthBitSet(int n, int k) 
{ 
    if ( (n >> k) & 1 )                 // Right Shift and Bitwise AND 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
}

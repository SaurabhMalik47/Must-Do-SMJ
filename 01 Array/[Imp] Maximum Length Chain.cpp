/*
Problem:
You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
Find the longest chain which can be formed from a given set of pairs. 

Input:
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output:
3
1

Explanation:
(i) The given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that can be formed is of length 3 
    and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain possible is only of length one.


/****************************** Time Complexity : O(n*logn) and Space Complexity : O(1) ******************************/
#include <bits/stdc++.h>
using namespace std;

class val
{
  public:
	int first;
	int second;
};

bool compare(val v1, val v2)
{
        return (v1.second < v2.second);
}

int maxChainLen(class val a[], int n)
{
    sort(a, a+n, compare);
    int i = 0, max = 1;
    for(int j=1; j<n; j++)
    {
        if(a[i].second < a[j].first)
        {       
            max++;
            i = j;
        }
    }
    return max;
}

int main() 
{
		int n;
		cin>>n;
		val a[n];
		for(int i=0; i<n; i++)
    {
			cin>>a[i].first>>a[i].second;
    }
	cout<<maxChainLen(a, n)<<endl;
	return 0;
}

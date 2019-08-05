/*
Problem:
Given a string, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
Determine the Minimum cuts needed for palindrome partitioning of a given string.
                                                        OR
Given a String S, find the minimum number of cuts required to separate the string into a set of palindromes.

Input:
ababbbabbababa
aaabba

Output:
3
1

Explaination:
Testcase 1 : Minimum 3 cuts are required for “ababbbabbababa”. The 3 cuts are “a | babbbab | b | ababa”.
Testcase 2 : Minimum 1 cut is required for “aaabba”. The 1 cut is "aa | abba"

/****************************** Time Complexity : O(n^2) and Space Complexity : O(n^2) ******************************/

Use DP 2 times : 1) Once for Calculating Palindrome
                 2) Then for Finding Minimum Cuts


/****************************** Time Complexity : O(n^2) and Space Complexity : O(n^2) ******************************/


#include<bits/stdc++.h>
using namespace std;

int MinimumPalindromePartition(string s)
{
	int n = s.length();
	bool isPalindrome[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			isPalindrome[i][j] = false;
			if(i==j || i==j+1)
				isPalindrome[i][j]=true;
		}
	}
	
// Fill the isPalindrome Matrix to mark all palindrome substrings
	int len = 1;
	while(len != n)
	{
		for(int i=0,j=len; ((i<n)&&(j<n)); i++,j++)
		{
			if((s[i]==s[j]) && isPalindrome[i+1][j-1])
				isPalindrome[i][j] = true;
		}
		len++;
	}


// Now Apply DP again to find minimum number of cuts

	int cuts[n] = {INT_MAX};
	for(int i=0; i<n; i++){
		if(isPalindrome[0][i]) 
		{
			cuts[i]=0;
		}
		else
		{
			cuts[i] = INT_MAX;
			for(int j=0;j<i;j++)
			{
				if(isPalindrome[j+1][i] && ((1+cuts[j])<cuts[i]) )
					cuts[i]=cuts[j]+1;
			}
		}
	}
return cuts[n-1];
}

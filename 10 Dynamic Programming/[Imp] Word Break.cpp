/*
Problem:
Given an input string and a dictionary of words, find out if the input string can be segmented into a 
space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary : { i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango}

Input : ilike
Output : Yes
The string can be segmented as "i like".

Input : ilikesamsung
Output : Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike

Output:
1
0


/****************************** Time Complexity : O(n) and Space Complexity : O(1) ******************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   string s, x;
   unordered_map<string, int> dict;
   for(int i=0; i<n; i++)
   {
      cin>>x;
      dict[x]++;
   }
   cin>>s;
   x = "";

   for(int i=0; i<s.length(); i++)
   {
      x += s[i];
      if(dict[x])
         x = "";
   }
         
   if(x == "")
      cout<<"1"<<endl;
   else
      cout<<"0"<<endl;
	return 0;
}

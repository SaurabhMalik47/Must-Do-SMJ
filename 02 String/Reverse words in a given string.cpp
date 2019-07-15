/*Reverse words in a given string
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr*/




using namespace std;

void reverse(string &s, int start, int end)
{
    int i = start, j = end;
    while(start<end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   string s;
	   cin>>s;
	   
	   int n = s.size();
	   int j=0;
       for(int i=0; i<n; i++)
       {
           if(s[i]=='.' || i==n-1)
           {
               if(s[i]=='.')
               {
                   reverse(s, j, i-1);
                   j=i+1;

               }
               else
               {
                   reverse(s, j, i);
               }
           }
       }
       
       for(int i=n-1; i>=0; i--)
       {
           cout<<s[i];
       }

	   cout<<endl;

	}
	return 0;
}

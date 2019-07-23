/*
Problem:
Consider a rat placed at (0, 0) in a square matrix m[][] of order n and has to reach the destination at (n-1, n-1). 
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible directions
which the rat can take to reach the destination at (n-1, n-1).
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Input:
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1

Output:
DRDDRR
DDRDRR DRDDRR

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR 
when printed in sorted order we get DDRDRR DRDDRR.





void RatInAMaze(int m[MAX][MAX], int n, vector<string> &ans, string s="", int x=0, int y=0)
{
	if(x==n-1 && y==n-1)
	{
		ans.push_back(s);
		return;
	}
    
		// Up
		if(x>0 && m[x-1][y])
		{
		    m[x][y]=0;
			RatInAMaze(m, n, ans, s+'U', x-1, y);
            m[x][y]=1;
		}
		// Down
		if(x<n-1 && m[x+1][y] )
		{
		    m[x][y]=0;
		    RatInAMaze(m, n, ans, s+'D', x+1, y);
		    m[x][y]=1;
		}
			
		// Right
		if(y<n-1 &&  m[x][y+1])
		{
		    m[x][y]=0;
		    RatInAMaze(m, n, ans, s+'R', x, y+1);
		    m[x][y]=1;
		}   
		
		// Left
		if(y>0 && m[x][y-1])
		{
		    m[x][y]=0;
		    RatInAMaze(m, n, ans, s+'L', x, y-1);
		    m[x][y]=1;
		}

}

vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> ans;

 	RatInAMaze(m, n, ans);
 	sort(ans.begin(), ans.end());
 	return ans;
}

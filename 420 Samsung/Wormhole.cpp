**********************************************WormHole******************************

#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x,y;
};
int dist (Point a, Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int travel (Point src, Point dst, Point st[], Point en[], bool vis[], int n)
{
    if (src.x==dst.x && src.y==dst.y) {
        return 0;
    }
    int ans=dist(src, dst);
    for (int i=0; i<n; i++) {
        if (vis[i]==false) {
            vis[i]=true;
            ans=min(ans, dist(src, st[i])+travel(en[i], dst, st, en, vis, n));
            ans=min(ans, dist(src, en[i])+travel(st[i], dst, st, en, vis, n));
            vis[i]=false;
        }
    }
    return ans;
}
int main ()
{
    Point src,dst;
    cin>>src.x>>src.y;
    cin>>dst.x>>dst.y;
    int n;
    cin>>n;
    Point st[n], en[n];
    for (int i=0; i<n; i++) {
        cin>>st[i].x>>st[i].y;
        cin>>en[i].x>>en[i].y;
    }
    bool vis[n];
    for (int i=0; i<n; i++) {
        vis[i]=false;
    }
    cout<<travel(src, dst, st, en, vis, n)<<endl;
    return 0;
}



*********************************************************************************************************

#include<iostream>
using namespace std;

int T;
int AnswerN;
int mask[10], w[10][5], n;

int distance(int sx, int sy, int dx, int dy) 
{
	int xd = (sx>dx) ? (sx-dx) : (dx-sx);
	int yd = (sy>dy) ? (sy-dy) : (dy-sy);
	return (xd+yd);
}

void calc(int sx, int sy, int dx, int dy, int dis) 
{
    AnswerN = min(AnswerN, distance(sx, sy, dx, dy) + dis);

	for(int i=0; i<n; i++) 
    {
		if(mask[i] == 0) 
        {
			mask[i]=1;
			int temp = distance(sx, sy, w[i][0], w[i][1]) + dis + w[i][4];
			calc(w[i][2], w[i][3], dx, dy, temp);
			temp = distance(sx, sy, w[i][2], w[i][3]) + dis + w[i][4];
			calc(w[i][0], w[i][1], dx, dy, temp);
			mask[i]=0;
		}
	}
}
int main(void) 
{
    std::ios::sync_with_studio(false);
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++)
    {
		cin>>n;
		int sx, sy, dx, dy;
		cin >> sx >> sy >> dx >> dy;

		for(int i=0; i<n; i++) 
        {
			mask[i] = 0;
			for(int j=0; j<5; j++) 
            {
				cin >> w[i][j];
			}
		}
		AnswerN = 999999;
		calc(sx, sy, dx, dy, 0);
		cout << "#" << test_case << " " << AnswerN <<endl; 
	}
	return 0;
}

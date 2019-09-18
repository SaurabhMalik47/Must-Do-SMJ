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

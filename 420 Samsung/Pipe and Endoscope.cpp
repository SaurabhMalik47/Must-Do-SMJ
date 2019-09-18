***************************************Pipe and Endoscope****************************************************

#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, l, a[1000][1000];
int q[10000000], front = -1, rear = -1;


void pushv(int n)
{
    if(rear==-1)
    {
        rear = 0;
        front = 0;
    }
    else
    rear++;
    q[rear] = n;
}


bool isEmpty()
{
    if(front==rear && rear==-1)
        return true;
    return false;
}


int popv()
{
    if(front==rear)
    {
        int temp = q[rear];
        front = -1;
        rear = -1;
        return temp;
    }
    front++;
    return(q[front-1]);
}


void clearQueue()
{
    front = -1;
    rear = -1;
}


long explorablePipes(int a[][1000], int x, int y, int l)
{
    if(l==0)
        return 0;
    if(x<0 || x>=n || y<0 || y>=m || a[x][y]==0)
        return 0;

    bool visited[n][m];
    int len[n][m];
    memset(visited, 0, sizeof(visited));

    pushv(y);
    pushv(x);
    int i, j;
    len[x][y] = 0;
    long count = 0;
    visited[x][y] = 1;
    while(!isEmpty())
    {
        j = popv();
        i = popv();
        if(len[i][j]<l)
        {
            count++;

            //TOP
            if(a[i][j]==1 || a[i][j]==2 || a[i][j]==4 || a[i][j] == 7)
            {
                if((i-1>=0) && !visited[i-1][j] && (a[i-1][j]==2 || a[i-1][j]==1 || a[i-1][j]==5 || a[i-1][j]==6))
                {
                    pushv(j);
                    pushv(i-1);
                    len[i-1][j] = len[i][j]+1;
                    visited[i-1][j] = 1;
                }
            }

            // BOTTOM
            if(a[i][j]==1 || a[i][j]==2 || a[i][j]==5 || a[i][j]==6)
            {
                if((i+1<n) && !visited[i+1][j] && (a[i+1][j]==1 || a[i+1][j]==2 || a[i+1][j]==4 || a[i+1][j]==7))
                {
                    pushv(j);
                    pushv(i+1);
                    len[i+1][j] = len[i][j]+1;
                    visited[i+1][j] = 1;
                }
            }

            // RIGHT
            if(a[i][j]==1 || a[i][j]==3 || a[i][j]==4 || a[i][j]==5)
            {
                if((j+1<m) && !visited[i][j+1] && (a[i][j+1]==1 || a[i][j+1]==3 || a[i][j+1]==6 || a[i][j+1]==7))
                {
                    pushv(j+1);
                    pushv(i);
                    len[i][j+1] = len[i][j]+1;
                    visited[i][j+1] = 1;
                }   
            }

            //LEFT
            if(a[i][j]==1 || a[i][j]==3 || a[i][j]==6 || a[i][j]==7)
            {
                if((j-1>=0) && !visited[i][j-1] && (a[i][j-1]==1 || a[i][j-1]==3 || a[i][j-1]==4 || a[i][j-1]==5))
                {
                    pushv(j-1);
                    pushv(i);
                    len[i][j-1] = len[i][j]+1;
                    visited[i][j-1] = 1;
                }
            }
        }
    }
    return count;
}




int main()
{
    int t, i, j;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> x >> y >> l;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin >> a[i][j];
            }
        }
        clearQueue();
        long ans = explorablePipes(a, x, y, l);
        cout << ans << endl;
    }
return 0;
}

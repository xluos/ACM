#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int x,y,s;
    bool friend operator < (Node a,Node b)
    {
        return a.s>b.s;
    }
};
int n,vis[55][55];
long long int dist[55][55],Map[55][55],dp[55][55];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void Bfs()
{
    memset(vis,0,sizeof(vis));
    priority_queue<Node> Q;

    Node cur,next;
    cur.x=n-1;cur.y=n-1;cur.s=Map[cur.x][cur.y];
    Q.push(cur);
    vis[n-1][n-1]=1;
    while(!Q.empty())
    {
        cur=Q.top();
        Q.pop();
        dist[cur.x][cur.y]=cur.s;
        for(int i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<n&&vis[next.x][next.y]==0)
            {
                next.s=Map[next.x][next.y]+cur.s;
                vis[next.x][next.y]=1;
                Q.push(next);
            }
        }
    }
}
long long dfs(int x,int y)
{
    if(dp[x][y]) return dp[x][y];
    if(x == n-1 &&y==n-1) return 1;
    for(int i=0; i<4; i++)
    {
        int x1=x+dir[i][0];
        int y1=y+dir[i][1];
        if(x1<0||x1>=n||y1<0||y1>=n||dist[x][y]<=dist[x1][y1])
            continue;
        dp[x][y]+=dfs(x1,y1);
    }
    return dp[x][y];
}
int main()
{
    while(cin>>n)
    {memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>Map[i][j];
            }
        }
        Bfs();
        cout<<dfs(0,0)<<endl;
    }
    return 0;
}


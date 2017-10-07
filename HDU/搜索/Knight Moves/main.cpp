#include <bits/stdc++.h>

using namespace std;
int dir[][2]={-1,2,-1,-2,1,2,1,-2,-2,1,-2,-1,2,1,2,-1};
struct node{
    int x,y;
    int step;
};
int vis[10][10];
int bfs(int x,int y,int tx,int ty)
{
    node q,p;
    q.x = x;
    q.y = y;
    q.step = 0;
    queue<node>Q;
    Q.push(q);
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if(p.x == tx&&p.y == ty)
        {
            return p.step;
        }
        for(int i = 0;i < 8;i++)
        {
            q.x = p.x + dir[i][0];
            q.y = p.y + dir[i][1];
            q.step = p.step + 1;
            if(q.x < 9&&q.x > 0&&q.y < 9&&q.y > 0&&!vis[q.x][q.y])
            {
                vis[q.x][q.y] = 1;
                Q.push(q);
            }
        }
    }
    return 0;
}
int main()
{
    char h[5],t[5];
    while(~scanf("%s %s",h,t))
    {
        //getchar();
        memset(vis,0,sizeof(vis));
        printf("To get from %s to %s takes %d knight moves.\n",h,t,bfs(h[0]-'a'+1,h[1]-'0',t[0]-'a'+1,t[1]-'0'));
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int N = 11;
int Chart[N][N],vis[N][N],X,Y;
int n,m,q1,q2;
int dir[][2] = {0,1,0,-1,1,0,-1,0};
struct node{
    int x,y;
    int step,time;
};
bool judge(node p)
{
    if(p.x<1||p.x>n||p.y<1||p.y>m||p.time<1)
        return false;
    return true;
}
int BFS(int x,int y)
{
    node q,p;
    queue<node>Q;
    q.x = x; q.y = y;
    q.step = 0; q.time = 6;
    Q.push(q);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        if(q.x == X&&q.y == Y&&q.time>0)
            return q.step;
        if(Chart[q.x][q.y] == 4&&q.time>0)
            q.time = 6;
        for(int i=0;i<4;i++)
        {
            int flag;
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.step = q.step + 1;
            p.time = q.time - 1;
            if(vis[p.x][p.y]!=4&&Chart[p.x][p.y] != 0&&judge(p))
            {
                vis[p.x][p.y] += 1;
                Q.push(p);
            }
        }
    }
    return -1;
}
int main()
{
    int w;
    scanf("%d",&w);
    while(w--)
    {
        scanf("%d %d",&n,&m);
        memset(Chart,0,sizeof(Chart));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&Chart[i][j]);
                if(Chart[i][j] == 2)
                {q1 = i;q2 = j;}
                else if(Chart[i][j] == 3)
                {X = i;Y = j;}
                else if(Chart[i][j] == 4)
                {
                    vis[i][j] = -2;
                }
            }
        }
        cout<<BFS(q1,q2)<<endl;
    }
    return 0;
}

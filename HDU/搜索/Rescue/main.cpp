#include <bits/stdc++.h>

using namespace std;
const int N = 205;
char Chart[N][N];
int vis[N][N],n,m,qx,qy,X,Y;
int dir[][2] = {0,1,0,-1,1,0,-1,0};
struct node{
    int x,y,step;
    friend bool operator < (node a,node b)
    {
        return a.step > b.step;
    }
};
bool judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||vis[x][y]||Chart[x][y] == '#')
        return false;
    return true;
}
int BFS(int x,int y)
{
    node q,p;
    priority_queue<node>Q;
    q.x = x; q.y = y;
    q.step = 0;
    Q.push(q);
    vis[x][y] = 1;
    while(!Q.empty())
    {
        q = Q.top();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.step = q.step + 1;
            if(p.x == X&&p.y == Y)
            {
                return p.step;
            }
            if(judge(p.x,p.y))
            {
                if(Chart[p.x][p.y] == 'x')
                    p.step++;
                vis[p.x][p.y] = 1;
                Q.push(p);
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        //memset(Chart,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            getchar();
            for(int j=0;j<m;j++)
            {
                scanf("%c",&Chart[i][j]);
                if(Chart[i][j] == 'a')
                {
                    qx = i; qy = j;
                    Chart[i][j] = '.';
                }
                else if(Chart[i][j] == 'r')
                {
                    X = i; Y = j;
                    Chart[i][j] = '.';
                }
            }
        }
        int step = BFS(qx,qy);
        if(~step) printf("%d\n",step);
        else printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}

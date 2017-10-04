#include <bits/stdc++.h>

using namespace std;
const int N = 10;
int Chart[N][N],vis[N][N][N][N],box_qx,box_qy,box_X,box_Y,qx,qy;
int n,m,w;
int dir[][2] = {0,1,0,-1,1,0,-1,0};
struct node{
    int x,y,step;
    int mx,my;
};
bool judge(node p)
{
    if(p.x<0||p.x>=n||p.y<0||p.y>=m||Chart[p.x][p.y] == 1)
        return false;
    return true;
}
bool bfs(int x,int y,node P,int k)
{
    node q,p;
    int X,Y;
    X = P.x - dir[k][0];
    Y = P.y - dir[k][1];
    queue<node>Q;
    int vis[N][N] = {0};
    vis[P.x][P.y] = 1;
    q.x = x;q.y = y;
    Q.push(q);
    vis[q.x][q.y] = 1;
    if(X == x&&Y==y) return true;
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            if(judge(p)&&!vis[p.x][p.y])
            {
                if(p.x == X&&p.y == Y)
                {
                    return true;
                }
                vis[p.x][p.y] = 1;
                Q.push(p);
                //printf("man: (%d ,%d)->(%d ,%d)\n",q.x,q.y,p.x,p.y);
            }
        }
    }
    return false;
}
int Box_BFS(int x,int y)
{
    node q,p;
    queue<node>Q;
    q.x = x;
    q.y = y;
    q.mx = qx;
    q.my = qy;
    q.step = 0;
    Q.push(q);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.step = q.step + 1;
            if(judge(p)&&!vis[p.x][p.y][q.x-dir[i][0]][q.y-dir[i][1]]&&bfs(q.mx,q.my,q,i))
            {
                if(p.x == box_X&&p.y == box_Y)
                    return p.step;
                vis[p.x][p.y][q.x-dir[i][0]][q.y-dir[i][1]] = 1;
                p.mx = q.x; p.my = q.y;
                Q.push(p);
                //printf("BOX: (%d ,%d)->(%d ,%d)\n",q.x,q.y,p.x,p.y);
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d",&w);
    while(w--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&Chart[i][j]);
                if(Chart[i][j] == 3)
                {
                    box_X = i;box_Y = j;
                    Chart[i][j] = 0;
                }
                else if(Chart[i][j] == 2)
                {
                    box_qx = i; box_qy = j;
                    Chart[i][j] = 0;
                }
                else if(Chart[i][j] == 4)
                {
                    qx = i; qy = j;
                    Chart[i][j] = 0;
                }
            }
        }
        cout<<Box_BFS(box_qx,box_qy)<<endl;
    }
    return 0;
}

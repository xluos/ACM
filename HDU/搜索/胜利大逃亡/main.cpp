#include <bits/stdc++.h>

using namespace std;
const int N = 55;
char Chart[N][N][N];
int vis[N][N][N],a,b,c,X,Y,Z,t;
int dir[][3] = {0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
struct node{
    int x,y,z,step;
};
bool judge(int x,int y,int z)
{
    if(x<0||x>=a||y<0||y>=b||z<0||z>=c||vis[x][y][z]||Chart[x][y][z] == 1)
        return false;
    return true;
}
int BFS(int x,int y,int z)
{
    node q,p;
    queue<node>Q;
    q.x = x; q.y = y; q.z = z;
    q.step = 0;
    Q.push(q);
    vis[x][y][z] = 1;
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        for(int i=0;i<6;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.z = q.z + dir[i][2];
            p.step = q.step + 1;
            if(X-p.x+Y-p.y+Z-p.z+p.step > t) continue;
            if(p.x == X&&p.y == Y&&p.z == Z)
            {
                return p.step > t ? -1:p.step;
            }
            if(judge(p.x,p.y,p.z))
            {
                vis[p.x][p.y][p.z] = 1;
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
        scanf("%d %d %d %d",&a,&b,&c,&t);
        memset(vis,0,sizeof(vis));
        //memset(Chart,0,sizeof(vis));
        for(int k = 0;k<a;k++)
        {
            for(int i=0;i<b;i++)
            {
                for(int j=0;j<c;j++)
                {
                    scanf("%d",&Chart[k][i][j]);
                }
            }
        }
        Y = b - 1; Z = c -1; X = a - 1;
        if(Chart[X][Y][Z] == 1) printf("-1\n");
        else printf("%d\n",BFS(0,0,0));
    }
    return 0;
}

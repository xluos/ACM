#include <bits/stdc++.h>

using namespace std;
const int N = 55;
char Chart[N][N][N];
int vis[N][N][N],n,m,c,qx,qy,qz,X,Y,Z,t;
int dir[][3] = {0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
struct node{
    int x,y,z,step;
};
bool judge(int x,int y,int z)
{
    if(x<0||x>=c||y<0||y>=n||z<0||z>=m||vis[x][y][z]||Chart[x][y][z] == 1)
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
        //cout<<q.x<<' '<<q.y<<' '<<q.z<<endl;
        for(int i=0;i<6;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.z = q.z + dir[i][2];
            p.step = q.step + 1;
            if(p.x == X&&p.y == Y&&p.z == Z)
            {
                return p.step;
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
        scanf("%d %d %d %d",&c,&n,&m,&t);
        memset(vis,0,sizeof(vis));
        //memset(Chart,0,sizeof(vis));
        for(int k = 0;k<c;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    scanf("%d",&Chart[k][i][j]);
                }
            }
        }

        Y = n - 1; Z = m -1; X = c - 1;
        int step = BFS(0,0,0);
        if(step <= t) printf("%d\n",step);
        else printf("-1\n");
    }
    return 0;
}

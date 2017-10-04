#include <bits/stdc++.h>

using namespace std;
const int N = 22;
int n,m,t,sx,sy,ex,ey;
char Chart[N][N];
int vis[N][N][1<<10+1],dir[][2] = {0,1,0,-1,1,0,-1,0};
struct node{
    int x,y,step,key;
};
bool judge(node p)
{
    int x = p.x,y = p.y;
    if(x<0||x>=n||y<0||y>=m||Chart[x][y] == '*')
        return false;
    return true;
}
int BFS(int x,int y)
{
    node q,p;
    queue<node>Q;
    q.x = x;q.y = y;
    q.step = 0; q.key = 0;
    vis[x][y][0] = 1;
    Q.push(q);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        for(int i = 0;i<4;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.step = q.step + 1;
            p.key = q.key;
            int flag = 1;
            if(p.x == ex&&p.y == ey)
            {
                return p.step>=t?-1:p.step;
            }
            if(judge(p))
            {
                if(Chart[p.x][p.y]>='a'&&Chart[p.x][p.y]<='j')
                {
                    p.key |= 1<<(Chart[p.x][p.y] - 'a' + 1);
                }
                else if(Chart[p.x][p.y]>='A'&&Chart[p.x][p.y]<='J')
                {
                    int ans = 1<<(Chart[p.x][p.y] - 'A' + 1);
                    if((p.key&ans) == 0||!p.key) flag = 0;
                    //printf("%d %d %d flag = %d %d\n",p.key,ans,p.key&ans,flag ,(p.key&ans) == 0);
                }
                if(flag&&!vis[p.x][p.y][p.key])
                {
                    vis[p.x][p.y][p.key] = 1;
                    Q.push(p);
                    //printf("(%d ,%d) %c key == %d step == %d \n",p.x,p.y,Chart[p.x][p.y],p.key,p.step);
                }
            }

        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d %d %d",&n,&m,&t))
    {
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++)
        {
            getchar();
            for(int j = 0;j<m;j++)
            {
                scanf("%c",&Chart[i][j]);
                if(Chart[i][j] == '@')
                {
                    sx = i;sy = j;
                }
                else if(Chart[i][j] == '^')
                {
                    ex = i;ey = j;
                    Chart[i][j] = '.';
                }
            }
        }
        printf("%d\n",BFS(sx,sy));
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#define N 305
#define M 305
using namespace std;
struct zuobiao{     //储存坐标和走到当前坐标所需最小步数
    int x,y;
    int sum;
    friend bool operator < (zuobiao a, zuobiao b)
    {
        return a.sum>b.sum;
    }
}p,k;
char  t[N][M];
int vis[N][M],n,m,kk;
int q_x,q_y,z_x,z_y;
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};//循环处理坐标上下左右
priority_queue<zuobiao>q;
int judge()
{
    if(k.x>=0&&k.x<N&&k.y>=0&&k.y<M&&
       (t[k.x][k.y]=='E'||t[k.x][k.y]=='B')&&vis[k.x][k.y]==0)
        return 1;
    return 0;
}
void bfs()
{
    memset(vis,0,sizeof(vis));
    while(!q.empty())q.pop();
    p.x=q_x;
    p.y=q_y;
    p.sum=0;
    q.push(p);
    vis[p.x][p.y]=1;
    while(!q.empty())
    {
        p=q.top();
        q.pop();
        if(p.x==z_x&&p.y==z_y)//判断是否是终点
        {
            cout<<p.sum<<endl;  //输出终点
            kk=0;
            break;
        }
        for(int i=0;i<4;i++)//四个方向
        {
            k.x=p.x+dir[i][0];
            k.y=p.y+dir[i][1];
            k.sum=p.sum+1;
            if(judge())//判断是否符合标准
            {
                if(t[k.x][k.y]=='B')
                    k.sum+=1;
                vis[k.x][k.y]=1;
                q.push(k);
            }
        }
    }
}
int main()
{
    int n,m;
    while(cin>>n>>m,n+m)
    {
        kk=1;
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<m;j++)
        {
            cin>>t[i][j];
            if(t[i][j]=='Y')
            {
                q_x=i;
                q_y=j;
            }
            if(t[i][j]=='T')
            {
                z_x=i;
                z_y=j;
                t[i][j]='E';
            }
        }
        }
        bfs();
        if(kk)cout<<-1<<endl;
    }
    return 0;
}

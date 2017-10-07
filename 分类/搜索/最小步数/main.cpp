//#include <iostream>
//#include <stdio.h>
//#include <queue>
//#include <cstring>
//#include <windows.h>
//using namespace std;
//struct zuobiao{
//    int x,y;
//    int sum;
//}p,k;
//int t[9][9]={
// {1,1,1,1,1,1,1,1,1},
// {1,0,0,1,0,0,1,0,1},
// {1,0,0,1,1,0,0,0,1},
// {1,0,1,0,1,1,0,1,1},
// {1,0,0,0,0,1,0,0,1},
// {1,1,0,1,0,1,0,0,1},
// {1,1,0,1,0,1,0,0,1},
// {1,1,0,1,0,0,0,0,1},
// {1,1,1,1,1,1,1,1,1}
//};
//int vis[9][9]={0};
//int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
//queue<zuobiao>q;
//void bfs(int q_x,int q_y,int z_x,int z_y)
//{
//    memset(vis,0,sizeof(vis));
//    while(!q.empty())q.pop();
//    p.x=q_x;
//    p.y=q_y;
//    p.sum=0;
//    q.push(p);
//    vis[p.x][p.y]=1;
//    while(!q.empty())
//    {
//        p=q.front();
//        q.pop();
//        if(p.x==z_x&&p.y==z_y)
//        {
//            cout<<p.sum<<endl;
//            break;
//        }
//        for(int i=0;i<4;i++)
//        {
//            k.x=p.x+dir[i][0];
//            k.y=p.y+dir[i][1];
//            k.sum=p.sum+1;
//            if(k.x>=0&&k.x<9&&k.y>=0&&k.y<9&&
//               t[k.x][k.y]==0&&vis[k.x][k.y]==0)
//            {
//                vis[k.x][k.y]=1;
//                q.push(k);
//            }
//        }
//    }
//}
//int main()
//{
//    int q_x,q_y,z_x,z_y,w;
//    cin>>w;
//    while(w--)
//    {
//        cin>>q_x>>q_y>>z_x>>z_y;
//        LARGE_INTEGER lFrequency;
//        QueryPerformanceFrequency(&lFrequency);
//        LARGE_INTEGER lBeginCount;
//QueryPerformanceCounter(&lBeginCount);
//        bfs(q_x,q_y,z_x,z_y);
//        LARGE_INTEGER lEndCount;
//QueryPerformanceCounter(&lEndCount);
//double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
//        printf("%lf",time*1000);
//    }
//    return 0;
//}
#include <iostream>
#include <queue>
#include <cstring>
#include <windows.h>
#include <stdio.h>
using namespace std;
struct Node{
    int x,y,stept;
};
int Map[9][9]={1,1,1,1,1,1,1,1,1,
 1,0,0,1,0,0,1,0,1,
 1,0,0,1,1,0,0,0,1,
 1,0,1,0,1,1,0,1,1,
 1,0,0,0,0,1,0,0,1,
 1,1,0,1,0,1,0,0,1,
 1,1,0,1,0,1,0,0,1,
 1,1,0,1,0,0,0,0,1,
 1,1,1,1,1,1,1,1,1};
 int vis[10][10];
 int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
 int sx,sy,ex,ey;
 void Bfs()
 {
     memset(vis,0,sizeof(vis));
     queue<Node> Q;
     Node cur,next;
     cur.x=sx;cur.y=sy;cur.stept=0;
     vis[cur.x][cur.y]=1;
     Q.push(cur);
     while(!Q.empty())
     {
         cur=Q.front();
         Q.pop();
         if(cur.x==ex&&cur.y==ey)
         {
             cout<<cur.stept<<endl;
             return;
         }
         for(int i=0;i<4;i++)
         {
             next.x=cur.x+dir[i][0];
             next.y=cur.y+dir[i][1];
             next.stept=cur.stept;
             if(next.x>=0&&next.x<9&&next.y>=0&&next.y<9&&vis[next.x][next.y]==0&&Map[next.x][next.y]==0)
             {
                 vis[next.x][next.y]==1;
                 next.stept+=1;
                 Q.push(next);
             }
         }

     }
 }
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>sx>>sy>>ex>>ey;
                LARGE_INTEGER lFrequency;
        QueryPerformanceFrequency(&lFrequency);
        LARGE_INTEGER lBeginCount;
        QueryPerformanceCounter(&lBeginCount);
        Bfs();
        LARGE_INTEGER lEndCount;
        QueryPerformanceCounter(&lEndCount);
        double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
        printf("运行时间%lf毫秒",time*1000);

    }
    return 0;
}

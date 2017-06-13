#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
struct zuobiao{
    int x,y;
}p,k;
int t[2000][2000];
int w,h,n;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
queue<zuobiao>q;
void bfs(int q_x,int q_y)
{
    while(!q.empty())q.pop();
    p.x=q_x;
    p.y=q_y;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            k.x=p.x+dir[i][0];
            k.y=p.y+dir[i][1];
            if(k.x>=0&&k.x<=h+1&&k.y>=0&&k.y<=w+1&&
               t[k.x][k.y]!=0)
            {
                t[k.x][k.y]=0;
                q.push(k);
            }
        }
    }
}
int main()
{
    int i,j;
    cin>>n;
    while(n--)
    {
        memset(t,-1,sizeof(t));
        cin>>w>>h;
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
                scanf("%d",&t[i][j]);
        bfs(0,0);
        for(i=1;i<=h;i++)
        {
            for(j=1;j<w;j++)
                printf("%d ",t[i][j]);
            printf("%d\n",t[i][j]);
        }
    }


    return 0;
}
//#include <iostream>
//#include <stdio.h>
//#include <cstring>
//using namespace std;
//int t[2000][2000];
//int w,h,n;
//int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
//void bfs(int x,int y)
//{
//    if(t[x][y]==0||(x<0||x>h||y<0||y>w))
//        return;
//    t[x][y]=0;
//    for(int i=0;i<4;i++)
//        bfs(x+dir[i][0],y+dir[i][1]);
//}
//int main()
//{
//
//    cin>>n;
//    while(n--)
//    {
//        memset(t,-1,sizeof(t));
//        cin>>w>>h;
//        for(int i=1;i<=h;i++)
//            for(int j=1;j<=w;j++)
//                scanf("%d",&t[i][j]);
//        bfs(0,0);
//        for(int i=1;i<=h;i++)
//        {
//            for(int j=1;j<=w;j++)
//                printf("%d ",t[i][j]);
//            printf("\n");
//        }
//    }
//
//
//    return 0;
//}
/*
10
6 5
1 1 0 1 0 1
1 1 0 1 0 1
1 1 0 0 0 1
1 1 0 1 0 1
1 1 0 0 0 1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
4 7
0 0 0 0
0 1 1 0
0 0 1 0
1 0 1 0
0 0 1 0
0 1 1 0
0 0 0 0
0 0 0 0
0 1 1 0
0 0 1 0
0 0 1 0
0 0 1 0
0 1 1 0
0 0 0 0*/

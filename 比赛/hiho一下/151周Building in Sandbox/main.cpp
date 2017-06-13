#include <iostream>
#include <bits/stdc++.h>
#define N 102
using namespace std;
int a[N][N][N];
int vis[N][N][N];
int dir[][3]={{0,0,-1},{0,0,1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
int dfs(int x,int y,int z)
{
    if(x>=N-1||y>=N-1||z>=N-1)
        return 1;
    for(int i=0;i<6;i++)
    {
        int X=x+dir[i][0],Y=y+dir[i][1],Z=z+dir[i][2];
        if(vis[X][Y][Z]==0)
        {
            vis[X][Y][Z] = 1;
            if(dfs(X,Y,Z))
                return 1;
            vis[X][Y][Z] = 0;
        }
    }
    return 0;
}
int judge(int x,int y,int z)
{
    int flag=1;
    int num[]={x,y,z};
    for(int i=0;i<6;i++)
    {
        if(a[x+dir[i][0]][y+dir[i][1]][z+dir[i][2]])
        {
            flag=0;
            break;
        }
    }
    return dfs(x,y,z);
//    if(flag){
//            return 0;
//    }
//    int j;
//    for(j=x;j<N;j++)
//    {
//        if(a[j][y][z])
//            break;
//    }
//    if(j==N-1)return 1;
//    for(j=x;j>0;j--)
//    {
//        if(a[j][y][z])
//            break;
//    }
//    if(j==0)return 1;
//    for(j=y;j<N;j++)
//    {
//        if(a[x][j][z])
//            break;
//    }
//    if(j==N-1)return 1;
//    for(j=y;j>0;j--)
//    {
//        if(a[x][j][z])
//            break;
//    }
//    if(j==0)return 1;
//    for(j=z;j<N;j++)
//    {
//        if(a[x][y][j])
//            break;
//    }
//    if(j==N-1)return 1;
//    for(j=z;j>0;j--)
//    {
//        if(a[x][y][j])
//            break;
//    }
//    if(j==0)return 1;
//    return 0;
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        int x,y,z;
        int flag=1;
        memset(a,0,sizeof(a));
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                a[i][j][0]=1;
                vis[i][j][0]=1;
            }
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if(flag&&judge(x,y,z))
            {
                a[x][y][z]=1;
                vis[x][y][z]=1;
            }
            else
            {
                if(flag=0)
                break;
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}

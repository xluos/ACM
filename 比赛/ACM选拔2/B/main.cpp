#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 25
using namespace std;
int a[N][3],vis[N],f[N],q;
int flag=0;
void DFS(int n,int num)
{
    if(n==q&&num==21)
    {
        flag++;
        printf("%d: ",flag);
        for(int i=0;i<20;i++)
        {
            printf(" %d",i==0?n:f[i]);
        }

        printf(" %d\n",n);
        return ;
    }
    for(int i=0;i<3;i++)
    {
        if(!vis[a[n][i]])
        {
            vis[a[n][i]]=1;
            f[num]=a[n][i];
            DFS(a[n][i],num+1);
            vis[a[n][i]]=0;
        }
    }
    return ;
}
int main()
{
    for(int i=1;i<=20;i++)
    {
        for(int j=0;j<3;j++)
            scanf("%d",&a[i][j]);
        sort(a[i],a[i]+3);
    }
    while(cin>>q,q)
    {
        memset(vis,0,sizeof(vis));
        int num=1;
        DFS(q,num);
    }
    return 0;
}

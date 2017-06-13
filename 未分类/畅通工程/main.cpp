#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 0x3f3f3f3f
using namespace std;
int main()
{
    int n,m,s,t;
    int a[205][205],vis[205][205];
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0x3f,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int x,y,s;
            scanf("%d %d %d",&x,&y,&s);
            if(a[x][y]>s)
            a[x][y]=a[y][x]=s;
        }
        for(int i=0;i<n;i++)
            a[i][i]=0;
        scanf("%d %d",&s,&t);
        for(int s=0;s<n;s++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=min(a[i][j],a[i][s]+a[s][j]);
        printf("%d\n",a[s][t]==MAX?-1:a[s][t]);
    }
    return 0;
}

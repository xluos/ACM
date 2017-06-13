#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int a[23][10005];
int n,m;
int maxx(int x,int y)
{
    int Max=-INF;
    for(int i=y+y;i<=m;i+=y)
    {
            Max=max(Max,a[x][i]);
    }
    if(x==n)
        return max(Max,a[x][y+1]);
    if(y==m)
        return max(Max,a[x+1][y]);
    return max(Max,max(a[x][y+1],a[x+1][y]));
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=n;i>0;i--)
        {
            for(int j=m;j>0;j--)
            {
                a[i][j]+=maxx(i,j);
            }
        }
        printf("%d\n",a[1][1]);
    }
    return 0;
}

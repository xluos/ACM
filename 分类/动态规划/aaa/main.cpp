#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n;
double Map[1005][1005];
void dijkstra(int x,int y)
{
    int s[1005],k;double dist[1005];
//    for(int i=0;i<n;i++)
//        dist[i]=-INF;
    for(int i=0;i<n;i++)
    {
        dist[i]=Map[x][i];
        s[i]=0;
    }
    s[x]=1;
    dist[x]=1.0;
    for(int i=0;i<n;i++)
    {
        double Max = -INF;
        for(int j=0;j<n;j++)
            if(s[j]==0&&Max<dist[j])
        {
            Max = dist[j];k=j;
        }
        s[k]=1;
        for(int j=0;j<n;j++)
        {
            if(s[j]==0&&dist[j]<Map[k][j]*dist[k])
                dist[j]=Map[k][j]*dist[k];
        }
    }
    if(dist[y]>0)
        printf("%.3lf\n",dist[y]);
    else
        printf("What a pity!\n");
}
int main()
{

    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%lf",&Map[i][j]);
            }
        int m,a,b;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            dijkstra(a-1,b-1);
        }
    }
    return 0;
}

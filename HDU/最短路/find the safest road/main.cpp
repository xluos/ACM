#include <bits/stdc++.h>

using namespace std;
const int N = 2004;
int n,m;
double Chara[N][N],dis[N];
int vis[N];
void Dijkstra(int src)
{
    for(int i=0;i<n;i++)
    {
        dis[i] = Chara[src][i];
        vis[i] = 0;
    }
    vis[src] = 1;
    dis[src] = 1;
    for(int j=0;j<n;j++)
    {
        double ans = 0;
        int k;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&dis[i]>ans)
            {
                ans = dis[i];
                k = i;
            }
        }
        vis[k] = 1;
        if(ans == 0) break;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&dis[i] < dis[k]*Chara[k][i])
                dis[i] = dis[k]*Chara[k][i];
        }
    }
}

int main()
{

    while(~scanf("%d",&n))
    {
        if(n>1001) while(1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double ans;
                scanf("%lf",&Chara[i][j]);
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            Dijkstra(a-1);
            if(dis[b-1]==0)
                printf("What a pity!\n");
            else
                printf("%.3lf\n",dis[b-1]);
        }


    }
    return 0;
}

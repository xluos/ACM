#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
int n,m;
int Chara[MAX][MAX],vis[MAX],dis[MAX];

void Dijstra(int sre)
{
    for(int i=1;i<=n;i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=1;i<=n;i++)
    {
        int k,minn = INF;
        for(int j = 1;j<=n;j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        vis[k] = 1;
        if(minn == INF) break;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && dis[j] > dis[k] + Chara[k][j])
            {
                dis[j] = dis[k] + Chara[k][j];
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m),n+m)
    {
        memset(Chara,INF,sizeof(Chara));
        memset(vis,0,sizeof(vis));
        int u,v,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(Chara[u][v] > w)
            {
                Chara[u][v] = w;
                Chara[v][u] = w;
            }
        }
        Dijstra(1);
        printf("%d\n",dis[n]);
    }
    return 0;
}

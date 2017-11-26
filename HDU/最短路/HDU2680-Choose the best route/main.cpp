#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
int n,m,t;
int Chara[MAX][MAX],vis[MAX],dis[MAX];

void Dijstra(int sre)
{
    for(int i=0;i<=n;i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=0;i<=n;i++)
    {
        int k,minn = INF;
        for(int j = 0;j<=n;j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        vis[k] = 1;
        if(minn == INF) break;
        for(int j=0;j<=n;j++)
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
    while(~scanf("%d %d %d",&n,&m,&t))
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
            }
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&v);
            Chara[0][v] = 0;
        }
        Dijstra(0);
        printf("%d\n",dis[t] == INF ? -1 : dis[t]);
    }
    return 0;
}

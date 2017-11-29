#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;
int n,m,t;
int Chara[MAX][MAX],vis[MAX],dis[MAX],dp[MAX*MAX],Weight[MAX];

void Dijstra(int sre)
{
    for(int i=0; i<=n; i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=0; i<=n; i++)
    {
        int k,minn = INF;
        for(int j = 0; j<=n; j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        if(minn == INF) break;
        vis[k] = 1;
        for(int j=0; j<=n; j++)
        {
            if(!vis[j] && dis[j] > dis[k] + Chara[k][j])
            {
                dis[j] = dis[k] + Chara[k][j];
            }
        }
    }
}

void ZeroOnePack(int V,int cost,int weight)
{
    for(int i = V; i >= cost; i--)
    {
        dp[i] = min(dp[i],dp[i-cost] + weight);
    }
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(dp,INF,sizeof(dp));
        dp[0] = 0;
        memset(Chara,INF,sizeof(Chara));
        memset(vis,0,sizeof(vis));
        int u,v,w,sum = 0,ans = 0;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(Chara[u][v] > w)
            {
                Chara[u][v] = w;
                Chara[v][u] = w;
            }
        }
        Dijstra(0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&Weight[i]);
            sum += Weight[i];
            if(dis[i] != INF)
            {
                ans +=Weight[i];
            }
        }
        if(ans <= sum/2.0)
        {
            printf("impossible\n");
        }
        else
        {
            for(int i=1; i<=n; i++)
            {
                ZeroOnePack(sum , Weight[i], dis[i]);
            }
            ans = sum/2+1;
            int minn = INF;
            for(int i = ans; i<=sum; i++)
            {
                if(dp[i]<minn)
                    minn = dp[i];
            }
            printf("%d\n",minn);
        }

    }
    return 0;
}

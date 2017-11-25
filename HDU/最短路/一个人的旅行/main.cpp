#include <bits/stdc++.h>

using namespace std;
const int INF=0x3f3f3f3f;
const int N=1008;

int n,m,s,t,d;
int Chara[N][N],dis[N],vis[N];

void Dijkstra(int src)
{
    for(int i=0; i<m; i++)
    {
        dis[i] = Chara[src][i];
        vis[i] = 0;
    }
    dis[src] = 0;
    vis[src] = 1;
    for(int i=0; i<m; i++)
    {
        int ans = INF,k;
        for(int j=0; j<m; j++)
        {
            if(!vis[j] && dis[j] < ans)
            {
                k = j;
                ans = dis[j];
            }
        }
        //cout<<"K = "<<k<<endl;
        vis[k] = 1;
        if(ans == INF) break;
        for(int j =0; j<m; j++)
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
    while(~scanf("%d %d %d",&t,&s,&d))
    {
        memset(Chara,0x3f,sizeof(Chara));
        int u,v,w;
        m = 0;
        for(int i=0;i<t;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(w < Chara[u][v])
                Chara[u][v] = Chara[v][u] = w;
            m = max(max(u,v),m);
        }
        m += 1;
        for(int i=0;i<s;i++)
        {
            scanf("%d",&v);
            Chara[1005][v] = 0;
        }
        Dijkstra(1005);
        int minn = INF;
        for(int i=0;i<d;i++)
        {
            scanf("%d",&n);
            if(minn > dis[n]) minn = dis[n];
        }
        cout<<minn<<endl;
    }
    return 0;
}

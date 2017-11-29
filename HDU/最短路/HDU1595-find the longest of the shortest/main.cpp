#include<bits/stdc++.h>

using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;

int n,m,flag = 1,maxx = 0;
int Chara[MAX][MAX],dis[MAX],vis[MAX],pre[MAX];

void Dijkstra(int sre)
{
    memset(vis,0,sizeof(vis));
    if(flag)
    {
        for(int i=0;i<=n;i++)
        {
            pre[i] = 1;
        }
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;

    for(int i = 1; i <= n; i++)
    {
        int k=0,minn = INF;
        for(int j = 1; j<=n; j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        if(minn == INF) break;
        vis[k] = 1;
        for(int j = 1; j<=n; j++)
        {
            if(!vis[j] && dis[j] >= dis[k] + Chara[k][j])
            {
                dis[j] = dis[k] + Chara[k][j];
                if(flag) pre[j] = k;
            }
        }
    }
}
void path(int tmp)
{
    //cout<<"path="<<n<<endl;
    if(tmp == 1)
    {
        return ;
    }
    path(pre[tmp]);
    int u = pre[tmp];
    int w = Chara[tmp][u];
    Chara[tmp][u] = INF;
    Chara[u][tmp] = INF;
    Dijkstra(1);
    //cout<<"del  "<<tmp<<'-'<<u<<' '<<dis[n]<<endl;
    if(dis[n]!=INF && dis[n] > maxx)
    {
        maxx = dis[n];
    }
    Chara[tmp][u] = w;
    Chara[u][tmp] = w;
    return ;
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        flag = 1;
        memset(Chara,INF,sizeof(Chara));
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            Chara[u][v] = w;
            Chara[v][u] = w;
        }
        Dijkstra(1);
        flag = 0;
        maxx = dis[n];
        //cout<<"maxx == "<<maxx<<endl;
        path(n);
        printf("%d\n",maxx);
    }
    return 0;
}

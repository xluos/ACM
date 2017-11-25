#include<bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;
const int N=210;

int n,m,s,t;
int Chara[N][N],dis[N],vis[N],sum[N];
struct node{
    int v; ///点
    int weight; ///权值
};
vector<node>mp[N]; //储存边;

///Floyd

void Floyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(Chara[i][k] + Chara[k][j] < Chara[i][j])
                {
                    Chara[i][j] = Chara[i][k] + Chara[k][j];
                }
            }
        }
    }
}
int main()
{

    while(~scanf("%d %d",&n,&m))
    {
        int u,v,w;
        memset(Chara,0x3f,sizeof(Chara));
        for(int i=0;i<=n;i++)
            Chara[i][i] = 0;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(w < Chara[u][v])
                Chara[u][v] = Chara[v][u] = w;
        }
        scanf("%d %d",&s,&t);
        Floyd();
        printf("%d\n",Chara[s][t]==INF?-1:Chara[s][t]);

    }
    return 0;
}
//SPFA写法
/*
void SPFA(int src)
{
    int q;
    queue<int>Q;
    vis[src] = 1;
    dis[src] = 0;
    Q.push(src);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i=0;i<mp[q].size();i++)
        {
            if(dis[q] + mp[q][i].weight < dis[mp[q][i].v])
            {
                dis[mp[q][i].v] = dis[q] + mp[q][i].weight;
                if(!vis[mp[q][i].v])
                {
                    Q.push(mp[q][i].v);
                    vis[mp[q][i].v] = 1;
                }
            }

        }
    }
    return ;
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        memset(dis,INF,sizeof(dis));
        memset(vis,0,sizeof(vis));

        int u,v,w;
        node ans;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            ans.v = v;
            ans.weight = w;
            mp[u].push_back(ans);
            ans.v = u;
            mp[v].push_back(ans);
        }
        scanf("%d %d",&s,&t);
        SPFA(s);
        printf("%d\n",dis[t]==INF?-1:dis[t]);
        for(int i=0;i<n;i++)
        {
            mp[i].clear();
        }
    }
    return 0;
}*/
/*
// Dijkstra 写法
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
    while(~scanf("%d %d",&m,&n))
    {
        int u,v,w;
        memset(Chara,0x3f,sizeof(Chara));
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(w < Chara[u][v])
                Chara[u][v] = Chara[v][u] = w;
        }
        scanf("%d %d",&s,&t);
        Dijkstra(s);
        printf("%d\n",dis[t]==INF?-1:dis[t]);
    }
    return 0;
}
*/

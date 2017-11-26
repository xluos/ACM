#include <bits/stdc++.h>

using namespace std;
const int MAX = 22*22;
const int INF = 0x3f3f3f3f;
int dis[MAX],vis[MAX];
int n,m;
struct node
{
    int v;
    int w;
} ;
vector<node>Chara[MAX];
void bulid(int v,int u,int m,char k)
{
    node ans;
    if(!m) ans.w = INF;
    else ans.w = 2520/m;
    if(k == '*')
    {
        ans.v = u;
        Chara[v].push_back(ans);
        ans.v = v;
        Chara[u].push_back(ans);
    }
    else if(k == 'v')
    {
        ans.v = u;
        Chara[v].push_back(ans);
    }
    else if(k == '^')
    {
        ans.v = v;
        Chara[u].push_back(ans);
    }
    else if(k == '<')
    {
        ans.v = v;
        Chara[u].push_back(ans);
    }
    else if(k == '>')
    {
        ans.v = u;
        Chara[v].push_back(ans);
    }
}
void SPFA(int sre)
{
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    int q;
    queue<int>Q;
    Q.push(sre);
    dis[sre] = 0;
    vis[sre] = 1;
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i=0;i<Chara[q].size();i++)
        {
            if(dis[Chara[q][i].v] > dis[q] + Chara[q][i].w)
            {
                dis[Chara[q][i].v] = dis[q] + Chara[q][i].w;
                if(!vis[Chara[q][i].v])
                {
                    Q.push(Chara[q][i].v);
                    vis[Chara[q][i].v] = 1;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m),n+m)
    {
        int v,M = m+1;
        char u;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d %c",&v,&u);
                bulid(i*M+j,i*M+j+1,v,u);
            }
            for(int j=0; j<m+1; j++)
            {
                scanf("%d %c",&v,&u);
                bulid(i*M+j,(i+1)*M+j,v,u);
            }
        }
        for(int j=0; j<m; j++)
        {
            scanf("%d %c",&v,&u);
            bulid(n*M+j,n*M+j+1,v,u);
        }
        SPFA(0);
        if(dis[(n+1)*(m+1)-1] == INF)
            printf("Holiday\n");
        else
            printf("%d blips\n",dis[(n+1)*(m+1)-1]);
        for(int i=0;i<MAX;i++)
        {
            Chara[i].clear();
        }
    }
    return 0;
}

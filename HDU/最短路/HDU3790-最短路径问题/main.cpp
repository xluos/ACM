#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;
int cost[MAX],dis[MAX],pre[MAX],vis[MAX];
int n,m;
struct node{
    int v,w,c;
};
vector<node>Chara[MAX];
void SPFA(int sre)
{
    int q;
    queue<int>Q;
    memset(dis,INF,sizeof(dis));
    memset(cost,INF,sizeof(cost));
    memset(vis,0,sizeof(vis));
    Q.push(sre);
    vis[sre] = 1;
    dis[sre] = 0;
    cost[sre] = 0;
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
                cost[Chara[q][i].v] = cost[q] + Chara[q][i].c;
                if(!vis[Chara[q][i].v])
                {
                    vis[Chara[q][i].v] = 1;
                    Q.push(Chara[q][i].v);
                }
            }
            else if(dis[Chara[q][i].v] == dis[q] + Chara[q][i].w)
            {
                if(cost[Chara[q][i].v] > cost[q] + Chara[q][i].c)
                {
                    cost[Chara[q][i].v] = cost[q] + Chara[q][i].c;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&m),n+m)
    {
        int a,b,d,p,s,t;
        node ans;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&d,&p);
            ans.v = b;
            ans.w = d;
            ans.c = p;
            Chara[a].push_back(ans);
            ans.v = a;
            Chara[b].push_back(ans);
        }
        scanf("%d %d",&s,&t);
        SPFA(s);
        printf("%d %d\n",dis[t],cost[t]);
        for(int i=0;i<MAX;i++)
        {
            Chara[i].clear();
        }
    }
    return 0;
}

/**
4 4
1 2 5 6
2 4 4 5
1 3 5 6
3 4 4 4
1 4
*/

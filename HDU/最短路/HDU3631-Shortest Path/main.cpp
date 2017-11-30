#include <bits/stdc++.h>

using namespace std;
const int MAX = 305;
const int INF = 0x3f3f3f3f;

int n,m,q,flag2;
int Chara[MAX][MAX],vis[MAX],dis[MAX],exist[MAX];

void Dijkstra(int sre)
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=0; i<n; i++)
    {
        int k,minn = INF;
        for(int j=0; j<n; j++)
        {
            if(exist[j]&&!vis[j]&&dis[j] < minn)
            {
                minn = dis[j];
                k = j;
            }
        }
        if(minn == INF) break;
        vis[k] = 1;
        for(int j=0; j<n; j++)
        {
            if(exist[j] && !vis[j] && dis[j] > dis[k] + Chara[k][j])
            {
                dis[j] = dis[k] + Chara[k][j];
            }
        }
    }
}
void Floyd(int k)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Chara[i][j] > Chara[i][k] + Chara[k][j])
            {
                Chara[i][j] = Chara[i][k] + Chara[k][j];
            }
        }
    }
}
int main()
{
    int t = 1;
    while(scanf("%d %d %d",&n,&m,&q),n+m+q)
    {
        if(t > 1) printf("\n");
        printf("Case %d:\n",t++);
        memset(Chara,INF,sizeof(Chara));
        memset(exist,0,sizeof(exist));
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(Chara[u][v] > w)
            {
                Chara[u][v] > w;
            }
        }
        for(int i=0; i<q; i++)
        {
            int flag; //�жϲ��뻹�ǲ���
            scanf("%d",&flag);
            if(flag)
            {
                scanf("%d %d",&u,&v);
                if(exist[u] && exist[v])
                {
                    //Dijkstra(u);
                    if(dis[v] == INF)
                        printf("No such path\n");
                    else
                        printf("%d\n",dis[v]);

                }
                else
                {
                    printf("ERROR! At path %d to %d\n",u,v);
                }
            }
            else
            {
                scanf("%d",&u);
                if(exist[u])
                {
                    printf("ERROR! At point %d\n",u);
                }
                else
                {
                    exist[u] = 1;
                    Floyd(u);
                }
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int MAX = 305;
const int INF = 0x3f3f3f3f;

int n,m,q,flag2;
int Chara[MAX][MAX],vis[MAX],dis[MAX],exist[MAX];

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
        for(int i=0;i<n;i++)
        {
            Chara[i][i] = 0;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(Chara[u][v] > w)
            {
                Chara[u][v] = w;
            }
        }
        for(int i=0; i<q; i++)
        {
            int flag; //判断插入还是查找
            scanf("%d",&flag);
            if(flag)
            {
                scanf("%d %d",&u,&v);
                if(exist[u] && exist[v])
                {
                    if(Chara[u][v] == INF)
                        printf("No such path\n");
                    else
                        printf("%d\n",Chara[u][v]);

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

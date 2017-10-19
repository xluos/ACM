#include<bits/stdc++.h>

using namespace std;

const int INF=0x3f3f3f3f;
const int N=210;

int n,m,s,t;
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
    //freopen("/home/xluos/Desktop/input.txt","r",stdin);
    while(~scanf("%d %d",&m,&n))
    {
        //cout<<"n,m:"<<n<<' '<<m<<endl;
        int u,v,w;
        memset(Chara,0x3f,sizeof(Chara));
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            if(w < Chara[u][v])
                Chara[u][v] = Chara[v][u] = w;//,cout<<"u,v,w: "<<u<<' '<<v<<' '<<w<<endl;
        }
        scanf("%d %d",&s,&t);
        //cout<<"s:t=="<<s<<' '<<t<<endl;
        Dijkstra(s);
        printf("%d\n",dis[t]==INF?-1:dis[t]);
    }
    return 0;
}

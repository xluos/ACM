#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;

int flag = 0,n,w,m,ans,sec[MAX],dis[MAX],vis[MAX];
struct node{
    int v;
    int w;
}no;

vector<node>ve[MAX];

void SPFA(int sre)
{
    int q;
    queue<int>Q;
    memset(dis,0xc0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[sre] = 100;
    vis[sre] = 1;
    Q.push(sre);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i=0;i < ve[q].size();i++)
        {
            if(dis[ve[q][i].v] < dis[q] + ve[q][i].w && dis[q] + ve[q][i].w > 0)
            {
                dis[ve[q][i].v] = dis[q] + ve[q][i].w;
                if(sec[ve[q][i].v] == -1) dis[ve[q][i].v] = INF;
                if(!vis[ve[q][i].v] && sec[ve[q][i].v] >= -1)
                {
                    Q.push(ve[q][i].v);
                    vis[ve[q][i].v] = 1;
                    sec[ve[q][i].v]--;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n),~n)
    {
        flag = 0;
        memset(sec,0,sizeof(sec));
        for(int i=1;i<=n;i++)
        {scanf("%d %d",&w,&m);
            no.w = w;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&ans);
                sec[ans]++;
                no.v = ans;
                ve[i].push_back(no);
            }
        }
        SPFA(1);
        if(dis[n] > 0)
        {
            printf("winnable\n");
        }
        else
        {
            printf("hopeless\n");
        }
        for(int i=0;i<MAX;i++)
        {
            ve[i].clear();
        }
    }
    return 0;
}
/**
6
0 2 2 5
1 1 3
1 1 4
1 1 2
-100 1 6
0 0
hopeless
*/

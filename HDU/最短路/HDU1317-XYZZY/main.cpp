#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
const int INF = 0x3f3f3f3f;

int n,w,m,ans,sec[MAX],dis[MAX],vis[MAX];
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
    memset(vis,INF,sizeof(vis));
    dis[sre] = 0;
    vis[sre] = 1;
    Q.push(sre);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i=0;i < ve[q].size();i++)
        {
            if(dis[ve[q][i].v] < dis[q] + ve[q][i].w)
            {
                dis[ve[q][i].v] = dis[q] + ve[q][i].w;
                if(!vis[ve[q][i].v] && sec[ve[q][i].v] >= 0)
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
        int i = 1;
        memset(sec,0,sizeof(sec));
        while(scanf("%d %d",&w,&m),w+m)
        {
            no.w = w;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&ans);
                sec[ans]++;
                no.v = ans;
                ve[i].push_back(no);
            }
            i++;
        }
        SPFA(1);
        for(int i=0;i<n;i++)
        {
            cout<<"dis== "<<dis[i]<<endl;
        }
        cout<<dis[n]<<endl;
        if(dis[n] + 100 > 0)
        {
            printf("winnable\n");
        }
        else
        {
            printf("hopeless\n");
        }
    }
    return 0;
}

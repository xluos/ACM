#include <bits/stdc++.h>

using namespace std;
const int MAX = 3005;
const int INF = 0x3f3f3f3f;

int n,m;
int Chara[MAX][MAX],vis[MAX],dis[MAX],mo[MAX];
vector<int>ve[MAX];

void SPFA(int sre)
{
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int>Q;
    int q;
    dis[sre] = 0;
    vis[sre] = 1;
    Q.push(sre);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i=0;i<MAX;i++)
        {
            if(!vis[i] && dis[i] > dis[q] + Chara[q][i])
            {
                dis[i] = dis[q] + Chara[q][i];
                if(!mo[i]) continue;
                else
                {
                    if(!vis[i])
                    {
                        Q.push(i);
                        vis[i] = 1;
                    }
                    for(int j=0;j<ve[i].size();j++)
                    {
                        int ans = ve[i][j];
                        mo[ans]--;
                        if(!mo[ans])
                        {
                            dis[ans] = max(dis[ans], dis[i]);
                            Q.push(ans);
                        }
                    }
                }

            }
        }
    }
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(Chara,0x3f,sizeof(Chara));
        memset(mo,0,sizeof(mo));
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            if(Chara[a][b] > w)
            {
                Chara[a][b] = w;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int l,li;
            scanf("%d",&l);
            mo[i] = l;
            for(int j=0;j<l;j++)
            {
                scanf("%d",&li);
                ve[i].push_back(li);
            }
        }
        SPFA(1);
        cout<<dis[n]<<endl;
    }
    return 0;
}

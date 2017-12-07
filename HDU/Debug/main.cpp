#include <bits/stdc++.h>

using namespace std;
const int MAX = 3005;
const int INF = 0x3f3f3f3f;

int n,m;
int Chara[MAX][MAX],vis[MAX],dis[MAX],mo[MAX],mp[MAX];
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
        for(int j=0; j<ve[q].size(); j++)
        {
            int ans = ve[q][j];
            mo[ans]--;
            mp[ans] = max(mp[ans],dis[q]);
            if(dis[ans]!=INF || mo[ans] == 0)
            {
                dis[ans] = max(mp[ans],dis[ans]);
                Q.push(ans);
                vis[ans] = 1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            int maxx = dis[q] + Chara[q][i];
            if(!vis[i] && dis[i] > maxx)
            {
                dis[i] = max(maxx,mp[i]);
                if(mo[i] > 0) continue;
                else
                {
                    if(!vis[i])
                    {
                        Q.push(i);
                        vis[i] = 1;
                    }

                }

            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(Chara,0x3f,sizeof(Chara));
        memset(mo,0,sizeof(mo));
        memset(mp,0,sizeof(mp));
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            if(Chara[a][b] > w)
            {
                Chara[a][b] = w;
            }
        }
        for(int i=1; i<=n; i++)
        {
            int l,li;
            scanf("%d",&l);
            mo[i] = l;
            for(int j=0; j<l; j++)
            {
                scanf("%d",&li);
                ve[li].push_back(i);
            }
        }
        SPFA(1);
        cout<<max(dis[n],mp[n])<<endl;
        for(int i=0; i<MAX; i++)
        {
            ve[i].clear();
        }
    }
    return 0;
}
/**
1
6 7
1 2 1
1 4 3
2 3 1
2 5 2
4 6 2
5 3 2
1 6 1
0
0
0
1 3
0
2 3 5

1
8 5
2 7 33
7 8 85
1 2 87
4 1 71
7 3 84
1 7
0
0
0
2 4 7
1 6
1 1
1 5


1
8 5
2 7 3
7 8 8
1 2 8
4 1 7
7 3 8
1 7
0
0
0
2 4 7
1 6
1 1
1 5

1
4 5
3 4 1
1 4 2
1 2 8
4 3 5
4 1 2
0
0
0
2 2 1

1
3 4
1 2 1
2 1 5
1 3 6
2 3 2
0
1 1
0
*/

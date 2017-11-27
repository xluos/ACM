#include <bits/stdc++.h>

using namespace std;
int N,C,R;
const int MAX = 105;
const int INF = 0x3f3f3f3f;

int Chara[MAX][MAX],vis[MAX],dis[MAX];

void Dijstra(int sre)
{
    for(int i=1;i<=N;i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=1;i<=N;i++)
    {
        int k,minn = INF;
        for(int j = 1;j<=N;j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        vis[k] = 1;
        if(minn == INF) break;
        for(int j=1;j<=N;j++)
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
    string s,t[1005];
    while(scanf("%d %d %d",&N,&C,&R),N+C+R)
    {
        cin>>s;cout<<s+"aaa"<<endl;
        for(int i=0;i<C;i++)
        {
            cin>>t[i];
            cout<<t[i]<<endl;
        }
    }
    return 0;
}

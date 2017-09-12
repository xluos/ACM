#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f
using namespace std;
struct node{
    int t;
    int l;
}no;
vector<node> Map[100005];
//struct node{
//
//
//}Map[100005];
int dist[100005],vis[100005],path[100005];
int n,k,m,a[1005];
void bfs(int k)
{
    queue<node>Q;
    for(int i=0;i<Map[k].size();i++)
    {
        Q.push(Map[k][i]);
    }
    while(!Q.empty())
    {
        node q=q.fon
    }
}
/*int dijkstra(int v)
{
    int mindist,u,t=v;
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<Map[v].size();i++)
    {
        dist[Map[v][i].t]=Map[v][i].l;
        //path[Map[v][i].t]=-1;
//        if(dist[i]<INF)
        path[Map[v][i].t]=v;
    }
    path[v]=-1;
    vis[v]=1;
    for(int i=1;i<=n;i++)
    {
        mindist = INF;
        for(int j=0;j<Map[u].size();j++)
        {
            if(vis[j]==0&&mindist>dist[j])
            {
                mindist=dist[j];
                u=j;
            }
        }
        vis[u]=1;
        for(int j=0;j<Map[u].size();j++)
        {
            if(vis[j]==0&&dist[j]>Map[u][j]+dist[u])
            {
                dist[j]=Map[u][j]+dist[u];
                path[j]=u;
            }
        }
    }
    if(dist[Map[u].size()-1]<INF)
            cout<<dist[Map[u].size()-1]-1<<endl;
        else
            cout<<"-1"<<endl;

}
void PrintPath(int D)
{
    if(path[D]!=-1)
    {
        PrintPath(path[D]);
        cout<<path[D]<<' ';
    }
}*/
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        //memset(Map,INF,sizeof(Map));
        cin>>n>>k>>m;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<k;j++)
                scanf("%d",&a[j]);
            for(int j=1;j<k;j++)
            {
                no.t=a[j];no.l=1;
                Map[a[j-1]].push_back(no);
               // Map[a[j-1]][a[j]]=1;
                //Map[a[j]][a[j-1]]
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<Map[i].size();j++)
                cout<<Map[i][j].t<<' ';
            cout<<endl;
        }
        bfs(1);
//        dijkstra(1);
       //   PrintPath(n);
    }
    return 0;
}

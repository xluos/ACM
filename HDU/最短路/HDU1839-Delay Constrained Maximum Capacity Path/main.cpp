#include <bits/stdc++.h>

using namespace std;
const int MAX = 10005;
const int INF = 0x3f3f3f3f;
struct node
{
    int v;  //点
    int w;  //时间
    int c;  //容量
};
int n,m,t;
int vis[MAX],dis[MAX],cap[MAX * 5];
vector<node>ve[MAX];
void SPFA(int sre,int T)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    dis[sre] = 0;
    vis[sre] = 1;
    queue<int>Q;
    int q;
    Q.push(sre);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i=0;i<ve[q].size();i++)
        {
            int k = ve[q][i].v,w = ve[q][i].w;
            if(ve[q][i].c >= T && dis[q] > dis[k] + w)
            {
                dis[q] = dis[k] + w;
                if(!vis[k])
                {
                    vis[k] = 1;
                    Q.push(k);
                }
            }
        }
    }
}
int main()
{
    int cnt;cin>>cnt;
    while(cnt--)
    {
        node ans;
        int a,b,c,d;
        scanf("%d %d %d",&n,&m,&t);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            ans.v = b;
            ans.w = d;
            ans.c = c;
            ve[a].push_back(ans);
            ans.v = a;
            ve[b].push_back(ans);
            cap[i] = c;
        }
        sort(cap,cap+m);
        for(int i=0;i<m;i++) cout<<cap[i]<<' ';
        int l = 0,r = m-1,mid=0;
        while(l<r)
        {
            mid = (l+r)/2+1;
            SPFA(1,cap[mid]);
            if(dis[n] <= t) l = mid;
            else r = mid;
        }
        cout<<cap[mid]<<endl;
        for(int i=0;i<MAX;i++)
        {
            ve[i].clear();
        }
    }
    return 0;
}

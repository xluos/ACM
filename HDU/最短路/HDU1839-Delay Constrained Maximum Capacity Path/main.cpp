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
    memset(dis,INF,sizeof(dis));
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
            int k = ve[q][i].v,w = ve[q][i].w,cc = ve[q][i].c;
            if(cc >= T && dis[k] > dis[q] + w)
            {
                dis[k] = dis[q] + w;
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
        //for(int i=0;i<m;i++) cout<<cap[i]<<' ';
        int l = 0,r = m-1,mid=0,ANS = cap[0];
        while(l<=r)
        {
            //cout<<l<<' '<<r<<' '<<mid<<endl;
            mid = (l+r)/2;
            SPFA(1,cap[mid]);
            if(dis[n] <= t) {ANS = cap[mid]; l = mid + 1;}
            else r = mid - 1;
        }
        cout<<ANS<<endl;
        for(int i=0;i<MAX;i++)
        {
            ve[i].clear();
        }
    }
    return 0;
}
/**

2
2 1 10
1 2 13 10
4 4 30
1 2 1000 15
2 4 999 6
1 3 100 15
3 4 99 4
*/

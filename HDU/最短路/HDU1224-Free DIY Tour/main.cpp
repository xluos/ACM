/**
1
3
0 10 20
3
1 2
2 3
1 4


1
4
0 10 20 30
6
1 2
2 3
3 4
4 5
1 4
2 4


1
4
0 10 -20 30
6
1 2
2 3
3 4
4 5
1 4
2 4
*/
/// 动态规划做法
#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int w,n,m,u,v;
int Chara[MAX][MAX],ve[MAX],vis[MAX],dis[MAX],pre[MAX];

void out(int n)
{
    stack<int>st;
    st.push(1);
    while(pre[n]!=1)
    {
        n = pre[n];
        st.push(n);
    }
    cout<<1;
    while(!st.empty())
    {
        cout<<"->"<<st.top();
        st.pop();
    }
    cout<<endl;
}
int main()
{
    int count = 1;
    cin>>w;
    while(w--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ve[i+1];
            pre[i+1] = 1;
        }
         pre[n+1] = 1;
        ve[n+1] = 0;
        memset(Chara,0,sizeof(Chara));
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            Chara[u][v] = 1;
        }
        for(int i=2;i <= n+1;i++)
        {
            for(int j = 1;j<i;j++)
            {
                if(Chara[j][i] && dis[j] + ve[i] > dis[i])
                {
                    dis[i] = dis[j] + ve[i];
                    pre[i] = j;
                }
            }
        }
        if(count > 1) printf("\n");
        printf("CASE %d#\npoints : %d\ncircuit : ",count++,dis[n+1]);
        out(n+1);
    }
    return 0;
}







///最短路做法
/*
#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int w,n,m,u,v;
int Chara[MAX][MAX],ve[MAX],vis[MAX],dis[MAX],pre[MAX];
struct node{
    int v; //点
    int w; //权
};
vector<node>vt[MAX];
void SPFA(int src)
{
    int q;
    vis[src] = 1;
    dis[src] = 0;
    queue<int>Q;
    Q.push(src);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        vis[q] = 0;
        for(int i = 0;i < vt[q].size();i++)
        {
            if(dis[q] + vt[q][i].w > dis[vt[q][i].v])
            {
                dis[vt[q][i].v] = dis[q] + vt[q][i].w;
                pre[vt[q][i].v] = q;
                if(!vis[vt[q][i].v])
                {
                    Q.push(vt[q][i].v);
                    vis[vt[q][i].v] = 1;
                }
            }
        }
    }
    return ;
}
void out(int n)
{
    stack<int>st;
    st.push(1);
    while(pre[n]!=1)
    {
        //printf("n= %d pre = %d\n",n , pre[n]);
        n = pre[n];
        st.push(n);
    }
    cout<<1;
    while(!st.empty())
    {
        cout<<"->"<<st.top();
        st.pop();
    }
    cout<<endl;
}
int main()
{
    int count = 1;
    cin>>w;
    while(w--)
    {
        node ans;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>ve[i+1];
            pre[i+1] = 1;
        }
         pre[n+1] = 1;
        ve[n+1] = 0;
        memset(Chara,0,sizeof(Chara));
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            ans.v = v;
            ans.w = ve[v];
            vt[u].push_back(ans);
        }
        SPFA(1);
        if(count > 1) printf("\n");
        printf("CASE %d#\npoints : %d\ncircuit : ",count++,dis[n+1]);
        out(n+1);
        for(int i=0;i<n+1;i++)
        {
            vt[i].clear();
        }
    }
    return 0;
}

*/

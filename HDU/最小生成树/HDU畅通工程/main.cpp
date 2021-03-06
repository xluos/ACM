#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int rANK[MAX],pre[MAX];
int n,m;
struct node{
    int u;  //边起点
    int v;  //边终点
    int w;  //边权值
};
vector<node>ve; //储存边
bool cmp(node a,node b)
{
    return a.w < b.w;
}
void Init(int n)
{
    for(int i = 0;i < n;i++)
    {
        pre[i] = i;
        rANK[i] = 0;
    }
}

int find_set(int x)
{
    if(pre[x] != x)
    {
        pre[x] = find_set(pre[x]);
    }
    return pre[x];
}
void join(int x,int y)
{
    int fx=find_set(x),fy=find_set(y);
    if(fx != fy)
    {
        if(rANK[fx] >= rANK[fy])
        {
            pre[fx]=fy;
            rANK[fx] += rANK[fy];
        }
        else
        {
            pre[fy]=fx;
            rANK[fx] += rANK[fy];
        }
    }
}
int Kruskal( )
{
    int sum = 0,edge_count = 0;  // sum代表最小生成树边权和，edge_count代表加入边的数量
    sort(ve.begin(),ve.end(),cmp);  //边按照权值升序排序
    for(int i=0; i < ve.size() && edge_count < m - 1; i++)  //边遍历完或以加入n-1条边退出循环
    {
        if(find_set(ve[i].u) != find_set(ve[i].v))  // 如果当前边加入不成环，就连接当前边
        {
            join(ve[i].u,ve[i].v);         //连接两点
            sum += ve[i].w;             //加入当前边的权值
            edge_count++;            //记录边的数量加一
        }
    }
    if(edge_count != m - 1)  //如果边数量不等于n-1 说明此图没有最小生成树
        return -1;
    return sum;       //返回最小边权和
}


int main()
{
    while(scanf("%d %d",&n,&m),n)
    {
        Init(m + 1);
        for(int i = 0; i < n; i++)
        {

            node ans;
            scanf("%d %d %d",&ans.u,&ans.v,&ans.w);
            ve.push_back(ans);
        }
        int t = Kruskal();
        if(~t)
        {
            printf("%d\n",t);
        }
        else
        {
            printf("?\n");
        }
        ve.clear();
    }

    return 0;
}

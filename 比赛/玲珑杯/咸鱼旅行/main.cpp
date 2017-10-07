//#include<iostream>
//#include<cstdio>
//#include<queue>
//#include<vector>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int maxn=100000+5;
//typedef pair<int,int> pii;
//struct Edge{
//    int to,weight;
//    Edge(int to,int weight):to(to),weight(weight){}
//};
//vector<vector<Edge> > G(maxn);  //更快
//struct Dijkstra{                //打包在Dijkstra中
//    int n,m;
//    bool done[maxn];
//    int dist[maxn];
//    int p[maxn];
//    Dijkstra(int n):n(n){
//        for(int i=0;i<n;i++) G[i].clear();
//    }
//    void AddEdge(int from,int to,int weight){
//        G[from].push_back(Edge(to,weight));  //保存from出发的边
//    }
//    void dijkstra(int s)
//    {
//        priority_queue<pii,vector<pii>,greater<pii> > Q;
//        memset(dist,0x7f,sizeof(dist));                  //初始化为无穷大
//        memset(done,false,sizeof(false));
//
//        dist[s]=0;
//        Q.push(pii(0,s));      //pii (dist ,u)
//        while(!Q.empty())
//        {
//            int u=Q.top().second; Q.pop();
//            if(done[u]) continue;     //可改为if(dist[u]!=Q.top().first) continue;
//            done[u]=true;
//            for(int i=0;i<G[u].size();i++)
//            {
//                Edge& e=G[u][i];
//                int v=e.to ,w=e.weight;
//                if(dist[v]>w)
//                {
//                    dist[v]=w;
//                    p[v]=u;            //记录到各点的最短路径
//                    Q.push(pii(dist[v],v));
//                }
//            }
//        }
//    }
//};
//int main()
//{
//    int n,m,u,v,w,s,t;
//    cin>>n>>m;       //n 点 , m 边
//    Dijkstra d(n);
//    for(int i=0;i<m;i++)
//    {
//        scanf("%d%d%d",&u,&v,&w);
//        d.AddEdge(u,v,w);
//    }
//    cin>>s>>t;
//    d.dijkstra(s);
//    if(d.dist[t]>1000000000)
//        cout<<-1<<endl;//1点出发
//    else
//        cout<<d.dist[t]<<endl;  //到n的最短路径
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxnum=10000;
const int maxint=999999;
int maxx=0;
//个数组下标都从1开始
int dist[maxnum];//表示以后点到源点的最短路径长度
int prev[maxnum];//记录以后点的前一个结点
int c[maxnum][maxnum];//记录图的两点间路径长度
int n,line;//图的节点数和路径数

void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
    bool s[maxnum]; // 判断是不是已存入该点到S集合中
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0; // 初始都未用过该点
        if(dist[i] == maxint)
            prev[i] = 0;
        else
        prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了全部V中顶点，dist就记录了从源点到全部其他顶点之间的最短路径长度
    // 注意是从第二个节点开始，第一个为源点
    for(int i=2; i<=n; ++i)
    {
        int tmp = maxint;
        int u = v;
        // 找出以后未应用的点j的dist[j]最小值
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j; // u保存以后邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1; // 表示u点已存入S集合中
        // 更新dist
        for(int j=1; j<=n; ++j)
        if((!s[j]) && c[u][j]<maxint)
        {
            int newdist = dist[u] + c[u][j];
            if(newdist < dist[j])
            {
                dist[j] = newdist;
                prev[j] = u;
            }
        }
    }
}
//查找从源点v到终点u的路径，并输出
void searchPath(int *prev,int v, int u)
{
    int tot = 1;
    int tmp = prev[u];
    while(tmp != v)
    {
        tot= tmp;
        tmp = prev[tmp];
        if(c[tot][tmp]>maxx)
            maxx=c[tot][tmp];
    }
    if(c[tot][tmp]>maxx)
        maxx=c[tot][tmp];
    cout<<maxx<<endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    // 各数组都从下标1开始
    // 输入结点数
    cin >> n;
    // 输入路径数
    cin >> line;
    int p, q, len; // 输入p, q两点及其路径长度
    // 初始化c[][]为maxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;
    for(int i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q]) // 有重边
        {
            c[p][q] = len; // p指向q
            c[q][p] = len; // q指向p，这样表示无向图
        }
    }
    int s,t;
    cin>>s>>t;
    for(int i=1; i<=n; ++i)
    dist[i] = maxint;
    Dijkstra(t, s, dist, prev, c);
    //最短路径长度
    searchPath(prev, s, t);
}

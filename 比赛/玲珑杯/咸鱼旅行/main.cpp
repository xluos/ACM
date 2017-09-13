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
//vector<vector<Edge> > G(maxn);  //����
//struct Dijkstra{                //�����Dijkstra��
//    int n,m;
//    bool done[maxn];
//    int dist[maxn];
//    int p[maxn];
//    Dijkstra(int n):n(n){
//        for(int i=0;i<n;i++) G[i].clear();
//    }
//    void AddEdge(int from,int to,int weight){
//        G[from].push_back(Edge(to,weight));  //����from�����ı�
//    }
//    void dijkstra(int s)
//    {
//        priority_queue<pii,vector<pii>,greater<pii> > Q;
//        memset(dist,0x7f,sizeof(dist));                  //��ʼ��Ϊ�����
//        memset(done,false,sizeof(false));
//
//        dist[s]=0;
//        Q.push(pii(0,s));      //pii (dist ,u)
//        while(!Q.empty())
//        {
//            int u=Q.top().second; Q.pop();
//            if(done[u]) continue;     //�ɸ�Ϊif(dist[u]!=Q.top().first) continue;
//            done[u]=true;
//            for(int i=0;i<G[u].size();i++)
//            {
//                Edge& e=G[u][i];
//                int v=e.to ,w=e.weight;
//                if(dist[v]>w)
//                {
//                    dist[v]=w;
//                    p[v]=u;            //��¼����������·��
//                    Q.push(pii(dist[v],v));
//                }
//            }
//        }
//    }
//};
//int main()
//{
//    int n,m,u,v,w,s,t;
//    cin>>n>>m;       //n �� , m ��
//    Dijkstra d(n);
//    for(int i=0;i<m;i++)
//    {
//        scanf("%d%d%d",&u,&v,&w);
//        d.AddEdge(u,v,w);
//    }
//    cin>>s>>t;
//    d.dijkstra(s);
//    if(d.dist[t]>1000000000)
//        cout<<-1<<endl;//1�����
//    else
//        cout<<d.dist[t]<<endl;  //��n�����·��
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxnum=10000;
const int maxint=999999;
int maxx=0;
//�������±궼��1��ʼ
int dist[maxnum];//��ʾ�Ժ�㵽Դ������·������
int prev[maxnum];//��¼�Ժ���ǰһ�����
int c[maxnum][maxnum];//��¼ͼ�������·������
int n,line;//ͼ�Ľڵ�����·����

void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
    bool s[maxnum]; // �ж��ǲ����Ѵ���õ㵽S������
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0; // ��ʼ��δ�ù��õ�
        if(dist[i] == maxint)
            prev[i] = 0;
        else
        prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
    // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
    // һ��S������ȫ��V�ж��㣬dist�ͼ�¼�˴�Դ�㵽ȫ����������֮������·������
    // ע���Ǵӵڶ����ڵ㿪ʼ����һ��ΪԴ��
    for(int i=2; i<=n; ++i)
    {
        int tmp = maxint;
        int u = v;
        // �ҳ��Ժ�δӦ�õĵ�j��dist[j]��Сֵ
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j; // u�����Ժ��ڽӵ��о�����С�ĵ�ĺ���
                tmp = dist[j];
            }
        s[u] = 1; // ��ʾu���Ѵ���S������
        // ����dist
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
//���Ҵ�Դ��v���յ�u��·���������
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
    // �����鶼���±�1��ʼ
    // ��������
    cin >> n;
    // ����·����
    cin >> line;
    int p, q, len; // ����p, q���㼰��·������
    // ��ʼ��c[][]Ϊmaxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;
    for(int i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q]) // ���ر�
        {
            c[p][q] = len; // pָ��q
            c[q][p] = len; // qָ��p��������ʾ����ͼ
        }
    }
    int s,t;
    cin>>s>>t;
    for(int i=1; i<=n; ++i)
    dist[i] = maxint;
    Dijkstra(t, s, dist, prev, c);
    //���·������
    searchPath(prev, s, t);
}

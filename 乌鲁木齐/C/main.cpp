#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f
int map1[10002][10002],dis[100002],visit[100002];///map1[][]存储所有边，
///dis[]存储第一个点到第i个点的路径长度，visit[]存储各点的访问状态
int start[100002],end1[100002],num[100005];
const int n=100002;
void dijstra(int s1)
{
    int i,j,pos=1,min1;
    memset(visit,0,sizeof(visit));
    for(i=1;i<=n;++i)
    {
        dis[i]=map1[s1][i];///第一个点到其他所有点的距离
    }
    visit[s1]=1;
    dis[s1]=0;
    for(i=1;i<n;i++)///剩余n-1个点，广度优先，依次求取距离原点的 最短路径长度
    {
        min1=inf;
        for(j=1;j<=n;++j)
        {
            if(!visit[j]&&min1>dis[j])
            {
                min1=dis[j];
                pos=j;
            }
        }///找到最小dis值

        visit[pos]=1;
        for(j=1;j<=n;++j)
        {
            if(!visit[j]&&dis[j]>dis[pos]+map1[pos][j])///1->j的距离是否可通过i->pos->j距离更短？
            dis[j]=dis[pos]+map1[pos][j];
        }
    }
}
int main()
{
    int ww;
    cin>>ww;
    while(ww--)
    {
        int i,j;
        int t,s=0,d=0;
        int n,m,maxx=0;
        scanf("%d %d",&n,&m);
        memset(map1,inf,sizeof(map1));
        memset(num,0,sizeof(num));
        int a,b,c;
        for(i=0; i<m; ++i) ///输入两点+权值
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a>b) swap(a,b);
            if(-c<map1[a][b])
                map1[a][b]=-c;
            if(num[a]==0)num[a] = -1;
            if(num[b]==0)num[b] = 1;
            if(num[a]==1) num[a] = 2;
            if(num[b]==-1) num[b] = 2;
        }
        int cnt=inf;
        for(int i=0; i<=n; i++)
        {
            cout<<i;
            if(num[i]==-1) start[s++] = i;
            if(num[i]== 1) end1[d++] = i;
        }
cout<<"asdasdasd";
        for(int i=0; i<s; i++)
        {
            dijstra(start[i]);///对每个起点使用
            for(int j=0; j<d; j++) ///求到多个目的地的距离中的最小
            {
                cnt=cnt>dis[end1[j]]?dis[end1[j]]:cnt;
            }
        }

        printf("%d\n",-cnt);

    }
    return 0;
}


//#include <iostream>
//#include <vector>
//#include <queue>
//#include <string.h>
//#include <cstdio>
//
//#define INF 0x3f3f3f3f
//
//using namespace std;
//
//struct node{
//int y;
//double  quan;
//}t;
//vector<node>mymap[2010];
//queue<int> Q;
//double d[2010];
//int  xx[2010];
//int main()
//{
//    memset(d,INF,sizeof(d));
//    memset(xx,INF,sizeof(xx));
//    int n,l;
//    cin>>n>>l;
//    for(int i=1;i<=l;i++)
//    {
//        int a,b;
//        double c;
//        cin>>a>>b>>c;
//        t.quan=c;
//        t.y=b;
//        mymap[a].push_back(t);
//        t.y=a;
//        mymap[b].push_back(t);
//    }
//    Q.push(1);
//    d[1]=0;
//    xx[1]=0;
//    while(!Q.empty())
//    {
//        int tmp=Q.front();
//        Q.pop();
//        xx[tmp]=INF;
//        for(unsigned int i=0;i<mymap[tmp].size();i++)
//        {
//            if(mymap[tmp][i].quan+d[tmp]<d[mymap[tmp][i].y] )
//            {
//                d[mymap[tmp][i].y]=mymap[tmp][i].quan+d[tmp];
//                if(xx[mymap[tmp][i].y]!=0)
//                {
//                    Q.push(mymap[tmp][i].y);
//                    xx[mymap[tmp][i].y]=0;
//                }
//            }
//        }
//    }
//    double sum=-1;
//    for(int i=1;i<n+1;i++)
//       sum=max(d[i],sum);
//    //cout<<sum<<endl;
//     printf("%.0lf",sum);
//    return 0;
//}
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdio>
#include <algorithm>
#define INF 1000000005
using namespace std;
long long  Map[2010][2010];
long long int Max,sum=0;
int n;
void Prim()
{
    long long int lowcost[2010],Min;
    int k;
    Max=-INF;
    for(int i=1;i<=n;i++)
    {
        lowcost[i]=Map[1][i];
    }
    for(int i=1;i<=n;i++)
    {
        Min=INF;
        for(int j=1;j<=n;j++)
        {
            if(lowcost[j]!=0&&lowcost[j]<Min)
            {
                Min=lowcost[j];k=j;
            }

        }
        if(Min==INF)break;
        if(Max<Min)
            Max=Min;
        lowcost[k]=0;
        for(int j=1;j<=n;j++)
            if(Map[k][j]!=INF&&Map[k][j]<lowcost[j])
                lowcost[j]=Map[k][j];
    }
}
int main()
{
    int m,a,b;
    long long int c;
    memset(Map,INF,sizeof(Map));
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %lld",&a,&b,&c);
        Map[a][b]=min(Map[a][b],c);
        Map[b][a]=Map[a][b];
    }
    Prim();
    printf("%lld\n",Max);
    return 0;
}


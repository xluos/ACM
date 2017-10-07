/*#include <bits/stdc++.h>
#define N 105
using namespace std;

int main()
{

    int w;
    while(scanf("%d",&w),w)
    {
        int a[N],b[N],suma=0,sumb=0;
        for(int i=0;i<w;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<w;i++)
            scanf("%d",&b[i]);
        sort(a,a+w);
        sort(b,b+w);
        for(int i=0;i<w;i++)
        {
            if(a[i]>b[i])
            {
                suma+=2;
            }
            else if(a[i]<b[i])
            {
                sumb+=2;
            }
            else
            {
                suma++;
                sumb++;
            }
        }
        printf("%d vs %d\n",suma,sumb);
    }
    return 0;
}

*/


#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>

#define  INF 0x3f3f3f3f
using namespace std;

struct node{
int y;
double quan;
}t;
double d[100005];
int xx[100005];
int chi[100005];
int in_degree[100005];

int main()
{
    int n;
    int l;
    while(scanf("%d%d",&m,&l)!=EOF)
    {
       bool ff=false;
       queue<int>Q;
       vector<node>mymap[100005];
       memset(d,0xc0c0c0c0,sizeof(d));
       memset(xx,INF,sizeof(xx));
       memset(chi,0,sizeof(chi));
       memset(in_degree,0,sizeof(in_degree));

       for(int i=0;i<=l;i++)
       {
        int a,b;
        double c;
        scanf("%d%d%lf",&a,&b,&c);
        t.quan=c;
        t.y=b;
        mymap[a].push_back(t);
        in_degree[b]++;
        t.y=a;
        mymap[b].push_back(t);
        in_degree[a]++;
       }


    }
    return 0;
}

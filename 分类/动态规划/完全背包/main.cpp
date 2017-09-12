#include <iostream>
#include <cstdio>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
int f[50005],v,c[2005],a[2005];
void CPack(int cost,int weight)
{
    for(int i=cost;i<=v;i++)
        f[i]=max(f[i],f[i-cost]+weight);
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n;
        scanf("%d%d",&n,&v);
        memset(f,0xc0,sizeof(f));
        f[0]=0;
        int a,c;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a,&c);
            CPack(a,c);
        }
        if(f[v]<0)
            printf("NO\n");
        else
            printf("%d\n",f[v]);
    }

    return 0;
}

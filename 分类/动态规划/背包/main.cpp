#include <iostream>
#include <cstdio>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
int f[100005],v,c[20],a[20];
void ZeroOnePack(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
    {
        f[i]=max(f[i],f[i-cost]+weight);
    }
}
void CPack(int cost,int weight)
{
    for(int i=cost;i<=v;i++)
        f[i]=max(f[i],f[i-cost]+weight);
}
void MultiplePack(int cost,int weight,int amount)
{
    if(cost*amount>=v)
    {
        CPack(cost,weight);
        return ;
    }
    int k=1;
    while(k<amount)
    {
        ZeroOnePack(k*cost,k*weight);
        amount-=k;
        k<<=1;
    }
    ZeroOnePack(amount*cost,amount*weight);
}
int main()
{
    while(~scanf("%d",&v))
    {
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&c[i]);
            MultiplePack(c[i],c[i],a[i]);
        }
        printf("%d\n",f[v]);
    }

    return 0;
}

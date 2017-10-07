#include <bits/stdc++.h>

using namespace std;
int f[10005],c[105],w[104],v;
int n,W;
void ZeroOnePack(int cost,int weight)
{
    for(int i=v; i>=cost; i--)
    {
//        int maxx=max(f[i],f[i-cost]+weight);
//        f[i]=maxx>W?f[i]:maxx;

        f[i]=min(f[i],f[i-cost]+weight);
    }
}
int main()
{

    while(~scanf("%d %d",&n,&W))
    {
        v=0;
        memset(f,0x3f,sizeof(f));
        f[0]=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&w[i],&c[i]);
            v+=c[i];
        }
        for(int i=0;i<n;i++)
        {
            ZeroOnePack(c[i],w[i]);
        }
        int maxxx=0;
        for(int i=v;i>0;i--)
        {
            if(f[i]<=W)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

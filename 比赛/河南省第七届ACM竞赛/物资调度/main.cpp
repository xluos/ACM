#include <bits/stdc++.h>
#define N 105
using namespace std;
int f[N*10];
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int v,n,c[N];
        scanf("%d %d",&n,&v);
        for(int i=0;i<n;i++)
        {
           scanf("%d",&c[i]);
        }
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=c[i];j<=v;j++)
            {
                f[j]=f[j]+f[j-c[i]];
            }
        }
        cout<<f[v]<<endl;
    }
    return 0;
}

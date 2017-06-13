#include <bits/stdc++.h>
#define N 100
using namespace std;
int f[N][N],c[N],w[N];
int main()
{
    int n,m,k,s;
    while(~scanf("%d %d %d %d",&n,&m,&k,&s))
    {
        memset(f,0,sizeof(f));
        for(int i=0;i<k;i++)
        {
             scanf("%d%d",&w[i],&c[i]);
        }
        for(int i=0;i<k;i++)
        {
            for(int j=c[i];j<=m;j++)
            {
                for(int t=1;t<=s&&j>=c[i]*t;t++)
                    f[j][t]=max(f[j][t],f[j-c[i]][t-1]+w[i]);
            }
        }
        int w=1;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=s; j++)
                if(f[i][j]>=n)
                {
                    printf("%d\n",m-i);
                    w=0;
                    break;
                }
            if(w==0)
                break;
        }
        if(w==1)
            printf("-1\n");

    }
    return 0;
}

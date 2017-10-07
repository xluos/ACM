#include <bits/stdc++.h>
#define N 509
using namespace std;
int f[N][N],ma[N];
int main()
{
    int maxx,n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int Max=0;
        memset(f,0,sizeof(f));
        for(int i=3; i<n+3; i++)
        {
            maxx=0;
            for(int j=3; j<m+3; j++)
            {
                scanf("%d",&f[i][j]);
                f[i][j]+=max(f[i][j-2],f[i][j-3]);
                if(maxx<f[i][j])maxx=f[i][j];
            }
            ma[i]=maxx;
            ma[i]+=max(ma[i-2],ma[i-3]);
            if(Max<ma[i])Max=ma[i];
        }
        cout<<Max<<endl;
    }
    return 0;
}

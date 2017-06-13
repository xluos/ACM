#include <bits/stdc++.h>
#define N 25
using namespace std;
int f[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        scanf("%d",&f[i][j]);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        f[i][j]+=max(f[i-1][j],f[i][j-1]);

    }
    cout<<f[n][m]<<endl;
    return 0;
}

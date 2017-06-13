#include <bits/stdc++.h>
#define N 55
using namespace std;
int f[2*N][N][N],data[N][N];
int max(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        memset(f,0,sizeof(f));
        int n,m,ma=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            scanf("%d",&data[i][j]);
        }
        for(int k=1;k<=m+n+1;k++)
        {
            for(int i_1=1;i_1<=k&&i_1<=n;i_1++)
            {
                for(int i_2=i_1+1;i_2<=k&&i_2<=n;i_2++)
                {
                    if(k-i_1>m||k-i_2>m)continue;
                    f[k][i_1][i_2]=max(f[k-1][i_1-1][i_2],f[k-1][i_1][i_2-1],
                                       f[k-1][i_1][i_2],f[k-1][i_1-1][i_2-1])
                                       +data[i_1][k-i_1]+data[i_2][k-i_2];
                    if(ma<f[k][i_1][i_2])ma=f[k][i_1][i_2];
                }
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}


#include <bits/stdc++.h>
#define N 55
using namespace std;
int f[2*N][N][N],data[N][N];
int max(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        memset(f,0,sizeof(f));
        int n,m,ma=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
        {
            scanf("%d",&data[i][j]);
        }
        for(int k=1;k<=m+n+1;k++)
        {
            for(int i_1=1;i_1<=k&&i_1<=n;i_1++)
            {
                for(int i_2=i_1+1;i_2<=k&&i_2<=n;i_2++)
                {
                    if(k-i_1>m+1||k-i_2>m+1)continue;
                    f[k][i_1][i_2]=max(f[k-1][i_1-1][i_2],f[k-1][i_1][i_2-1],
                                       f[k-1][i_1][i_2],f[k-1][i_1-1][i_2-1])
                                       +data[i_1][k-i_1]+data[i_2][k-i_2];
                    if(ma<f[k][i_1][i_2])ma=f[k][i_1][i_2];
                }
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}

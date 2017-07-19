#include <bits/stdc++.h>

using namespace std;
int mn[1005][1005],a[10005],n,m;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    memset(mn,-1,sizeof(mn));
    int N;cin>>N;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+N,cmp);
    for(m=1;m*m<N;m++);
    for(n=m;n*m!=N;n--);
    for(int k=0,i=1,j=1;k<N;)
    {
        for(;j<=n&&mn[i][j]==-1&&k<N;j++,k++) mn[i][j]=a[k];
        for(;i<=m&&mn[i][j]==-1&&k<N;i++,k++) mn[i][j]=a[k];
        for(;j>0&&mn[i][j]==-1&&k<N;j--,k++) mn[i][j]=a[k];
        for(;i>0&&mn[i][j]==-1&&k<N;i--,k++) mn[i][j]=a[k];
    }
    for(int i=1;i<=m+1;i++)
        for(int j=1;j<=n+1;j++)
            printf("%d%c",mn[i][j],j==n?'\n':' ');
    return 0;
}

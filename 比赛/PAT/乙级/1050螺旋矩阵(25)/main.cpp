#include <bits/stdc++.h>

using namespace std;
int a[10005],n,m;
int cmp(int a,int b)
{
    return a>b;
}
vector<vector<int> >mn;
vector<int>mm;
int main()
{

    int N;cin>>N;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+N,cmp);
    n=sqrt(N);
    while(n>1&&N%n!=0)n--;
    m=N/n;
    for(int j=0;j<=n+1;j++)
        mm.push_back(-1);
    for(int i=0;i<=m+1;i++)
    {
        mn.push_back(mm);
    }
    for(int k=0,i=0,j=0;k<N;)
    {
        for(i++,j++;j<=n&&mn[i][j]==-1&&k<N;j++,k++) mn[i][j]=a[k];
        for(j--,i++;i<=m&&mn[i][j]==-1&&k<N;i++,k++) mn[i][j]=a[k];
        for(i--,j--;j>0&&mn[i][j]==-1&&k<N;j--,k++) mn[i][j]=a[k];
        for(j++,i--;i>0&&mn[i][j]==-1&&k<N;i--,k++) mn[i][j]=a[k];
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            printf("%d%c",mn[i][j],j==n?'\n':' ');
    return 0;
}

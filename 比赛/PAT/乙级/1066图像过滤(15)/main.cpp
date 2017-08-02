#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,mn[505][505],a,b,k;
    cin>>n>>m>>a>>b>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mn[i][j];
            if(mn[i][j]<=b&&mn[i][j]>=a) mn[i][j]=k;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%03d%c",mn[i][j],j==m-1?'\n':' ');
        }
    }
    return 0;
}

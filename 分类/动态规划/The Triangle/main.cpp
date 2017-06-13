#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[105][105];
    int w;cin>>w;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=w;i++)
        for(int j=1;j<=i;j++)
    {
        scanf("%d",&dp[i][j]);
    }
    for(int i=w-1;i>0;i--)
        for(int j=1;j<=i;j++)
    {
        dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
    }
    cout<<dp[1][1]<<endl;
    return 0;
}

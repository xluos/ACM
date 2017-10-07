#include <iostream>
#include <bits/stdc++.h>
#define  INF 0x3f
using namespace std;
int dp[100];
int main()
{
    int n,k,c;
    while(~scanf("%d %d %d",&n,&k,&c))
    {
        int a[105];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n>k)
        {
            memset(dp,INF,sizeof(dp));
            dp[0]=0;
            for(int i=k; i<=n; i++)
            {
                for(int j=0; j<=i-k; j++)
                {
                    dp[i] = min(dp[i],dp[j]+c+(a[i]-a[j+1])*(a[i]-a[j+1])) ;
                }
            }
            printf("%d\n",dp[n]);
        }
        else
        {
            printf("%d\n",c+(a[n]-a[1])*(a[n]-a[1]));
        }
    }
    return 0;
}

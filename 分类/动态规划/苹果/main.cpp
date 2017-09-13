#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define N 1005
using namespace std;
int w[N],c[N],dp[N];
int n,v;
void Zero_One_Park(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}
int main()
{

    while(scanf("%d %d",&n,&v),v+n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&c[i],&w[i]);
        }
        for(int i=0;i<n;i++)
            Zero_One_Park(c[i],w[i]);
        cout<<dp[v]<<endl;
    }
    return 0;
}

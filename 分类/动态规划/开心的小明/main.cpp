#include <bits/stdc++.h>
#define N 30005
using namespace std;
int dp[N],v,n,c[N],w[N];
void Zero_One_Park(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int k;
        cin>>v>>n;
        for(int i=0;i<n;i++)
        {
           cin>>c[i]>>k;
           w[i]=c[i]*k;
        }
        for(int i=0;i<n;i++)
            Zero_One_Park(c[i],w[i]);
        cout<<dp[v]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
} data[1005];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int n,m;cin>>n;
    while(n--)
    {
        int k,ma=0;
        cin>>k;
        int dp[1005],dp2[1005];
        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&data[i].x,&data[i].y);
            dp[i]=1;
            dp2[i]=1;
        }
        sort(data,data+k,cmp);
        for(int i=1; i<k; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(data[i].y>data[j].y&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
                if(data[i].y<data[j].y&&dp2[j]+1>dp2[i])
                {
                    dp2[i]=dp2[j]+1;
                }
                ma=max(ma,max(dp[i],dp2[i]));
            }
        }
        printf("%d\n",ma);
    }
    return 0;
}


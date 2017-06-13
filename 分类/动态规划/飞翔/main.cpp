


#include <bits/stdc++.h>
#define q2 1.414213562373095
using namespace std;
struct node
{
    int x,y;
} data[1005];
int cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        int k,ma=0;
        cin>>k;
        int dp[1005];
        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&data[i].x,&data[i].y);
            dp[i]=1;
        }
        sort(data,data+k,cmp);
        for(int i=1; i<k; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(data[i].x>data[j].x&&data[i].y>data[j].y&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
                if(ma<dp[i])
                    ma=dp[i];
            }
        }
        printf("%.0lf\n",(m+n-2*ma)*100.0+q2*ma*100);
    }
    return 0;
}


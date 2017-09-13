#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int w[25],i,n,minn,ans,sum,t;
void dfs(int m)
{
    ans=fabs(sum-2*t);
    if(ans<minn)minn=ans;
    if(m==n)return;
    for(int i=m;i<n;i++)
    {
        t+=w[i];
        dfs(i+1);
        t-=w[i];
    }
    //return ;
}
int main()
{
    while(cin>>n)
    {
        t=sum=0;minn=0x3f3f3f3f;
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            sum+=w[i];
        }
        dfs(0);
        printf("%d\n",minn);
    }
    return 0;
}

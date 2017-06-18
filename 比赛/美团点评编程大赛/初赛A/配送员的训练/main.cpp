#include <bits/stdc++.h>

using namespace std;

int main()
{
    double v,u,c[1005],d[1005],l,sum=0,ans=0;
    int n;
    cin>>n>>v>>u;
    l=n*u;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int k=(j+i)%n;
            ans+=l/(c[k]-j*d[k]-v);
        }
        sum+=ans;
        ans=0;
    }
    printf("%.3lf\n",sum/n);
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct yl{
    int a,b;
    int YN;
};
int baos[100005],baof[100005];
map<int,yl>mp;
int fei(int i)
{
    if(mp[i].YN==0)
        return baos[i];
    if(baof[i]>0)
        return baof[i];
    baof[i]=fei(mp[i].a)+fei(mp[i].b);
    return baof[i];
}
int main()
{
    cout<<sizeof(yl)<<endl;
    int w;cin>>w;
    while(w--)
    {
        int n,m;
        memset(baof,-1,sizeof(baof));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&baos[i]);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            mp[c].a=a;mp[c].b=b;
            mp[c].YN=1;
        }
        for(int i=1;i<=n;i++)
        {
            int ans=fei(i);
            printf("%d ",ans>baos[i]?baos[i]:ans);
        }
    }
    return 0;
}

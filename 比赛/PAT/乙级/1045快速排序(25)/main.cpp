#include <bits/stdc++.h>
#define INF 1000000005
using namespace std;

int main()
{
    int n,a[100005],j=0,b[100005],maxx=-1,minn=0;
    map<int,int>mp;
    vector<int>ve;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
        mp[a[i]]++;
    }
    b[n]=INF;mp[INF]=1;
    sort(b,b+n+1);
    for(int i=0;i<n;i++)
    {
        mp[a[i]]--;
        while(!mp[b[maxx]]) maxx++;
        //printf("%d %d %d---max==%d\n",minn,a[i],b[maxx],maxx);
        if(a[i]>minn&&a[i]<b[maxx])
        {
            ve.push_back(a[i]);
        }
        minn=max(a[i],minn);
    }
    sort(ve.begin(),ve.end());
    cout<<ve.size()<<endl;
    if(ve.size()) cout<<ve[0];
    for(int i=1;i<ve.size();i++)
    {
        printf(" %d",ve[i]);
    }
    cout<<endl;
    return 0;
}

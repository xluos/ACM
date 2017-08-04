#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int a[MAX];
int suan(int n)
{
    int ans=n;
    while(ans)
    {
        n+=ans%10;
        ans/=10;
    }
    return n;
}
int main()
{
    int n,ans;
    cin>>n;
    for(int i=0;i<MAX;i++)
    {
        if(!a[suan(i)])a[suan(i)]=i;
    }
    while(n--)
    {
        cin>>ans;
        cout<<a[ans]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,t,a[30005],sum=1;
    cin>>n>>t;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(sum<t)
    {
        sum+=a[sum];
    }
    if(sum==t)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

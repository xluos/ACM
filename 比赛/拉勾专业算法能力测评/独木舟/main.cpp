#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,sum=0;
    int a[10006];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int l=0,r=n-1;
    for(;l<r;)
    {
       if(a[r]+a[l]<=m)
       {
           sum++;
           r--;l++;
       }
       else
       {
           sum++;
           r--;
       }
    }
    if(r==l)sum++;
    cout<<sum<<endl;
    return 0;
}

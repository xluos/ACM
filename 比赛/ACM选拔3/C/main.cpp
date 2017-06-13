#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100005],l[100005];
    int w,k=0;cin>>w;
    while(w--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]-=i;
        }
        int t=0;
        l[t++]=a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]>=l[t-1])
            {
                l[t++]=a[i];
            }
            else
            {
                int mid=lower_bound(l,l+t,a[i])-l;
                l[mid]=a[i];
            }
        }
        printf("Case #%d:\n%d\n",++k,n-t);
    }
    return 0;
}

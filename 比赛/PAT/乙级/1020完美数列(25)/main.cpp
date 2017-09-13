#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,p,a[100005],maxx=0;
    scanf("%lld %lld",&n,&p);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n-maxx;i++)
    {
        int ans=upper_bound(a+i,a+n,a[i]*p)-a;//因为查找到的是第一个大于查找值的地址，它的下一个就是<=a[i]*p了
        if(ans-i>maxx)//然后ans-i就是第i个到ans个之间的数量
            maxx=ans-i;
    }
    cout<<maxx<<endl;
    return 0;
}

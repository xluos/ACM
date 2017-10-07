#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100005];
int main()
{
    int w;cin>>w;
    while(w--)
    {
        memset(a,0,sizeof(a));
        int n;cin>>n;
        long long sum=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(sum<a[i]-1)
                break;
            sum+=a[i];
        }
        printf("%lld\n",sum);
    }
}















/*#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100005];
long long f[100000005];
int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n,t,sum=0;cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(t=0,sum=a[0];t<n-1;t++)
        {
            if(sum<a[t+1]-1)
                break;
            sum+=a[t+1];
        }
        memset(f,0xc0,sizeof(f));
        cout<<f[0];
        f[0]=0;
        for(int i=0;i<t;i++)
        {
            for(int j=sum;j>=a[i];j--)
            {
                f[j]=max(f[j],f[j-a[i]]+a[i]);
            }
        }
        for(t=sum;t>=0;t++)
            if(f[t]>0)
        {
            cout<<t<<endl;
            break;
        }
    }
    return 0;
}*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n,a[10005],b[10005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    b[0]=a[0];b[n-1]=a[n-1];
    for(int i=1;i<n-1;i++)
    {
        int temp1,temp2;
        temp1=a[i]-b[i-1];
        temp2=a[i]-a[i+1];
        if(temp1>0&&temp2>0)
            b[i]=max(b[i-1],a[i+1]);
        else if(temp1<0&&temp2<0)
            b[i]=min(b[i-1],a[i+1]);
        else
            b[i]=a[i];
    }
//    for(int i=0;i<n;i++)
//        cout<<b[i]<<' ';
//    cout<<endl;
    int v=0;
    for(int i=0;i<n;i++)
        v+=abs(a[i]-b[i]);
    for(int i=1;i<n;i++)
        v+=abs(b[i-1]-b[i]);
    printf("%d\n",v);
    return 0;
}

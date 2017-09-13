#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int sum,sum2,n,a[100006];
    sum=sum2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int l=n/2;
    for(int i=0;i<l;i++)
    {
        sum+=a[i];
    }
    for(int i=l;i<n;i++)
    {
        sum2+=a[i];
    }
    printf("Outgoing #: %d\n",n-l);
    printf("Introverted #: %d\n",l);
    printf("Diff = %d\n",sum2-sum);
    return 0;
}

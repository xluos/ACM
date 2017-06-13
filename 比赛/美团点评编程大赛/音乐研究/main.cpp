#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[1005],b[1005];
    long long sum=0,maxx=0x3f3f3f3f;
    int n,m,flag=0;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    cin>>m;
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<m-n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum+=(a[j]-b[i+j])*(a[j]-b[i+j]);
        }
        if(sum<maxx)
            maxx=sum;
        sum=0;
    }
    cout<<maxx<<endl;
    return 0;
}

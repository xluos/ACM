#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[100005],j=0,b[100005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(a[0]<a[1])b[j++]=a[0];
    for(int i=1;i<n-1;i++)
    {
        if(a[i]>a[i-1]&&a[i]<a[i+1])
            b[j++]=a[i];
    }
    if(a[n-1]>a[n-2])b[j++]=a[n-1];
    sort(b,b+j);
    cout<<j<<endl;
    for(int i=0;i<j-1;i++)
    {
        cout<<b[i]<<' ';
    }
    cout<<b[j-1]<<endl;
    return 0;
}

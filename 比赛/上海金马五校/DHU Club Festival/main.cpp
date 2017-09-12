#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[110],n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int sum=a[0];
        for(int i=1;i<n;i++)
        {
            sum=(sum+a[i])/2;
        }
        cout<<sum<<endl;
    }
    return 0;
}

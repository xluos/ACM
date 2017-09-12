#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,sum=0;
    int a[50005];
    cin>>n>>m;
    a[n]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        int ans;
        scanf("%d",&ans);
        if(ans<=a[0])
        {
            sum++;
            for(int i=0;i<=n;i++)
            {
                if(ans>a[i])
                    a[i-1]=0;
            }
        }
        else
        {
            a[0]=0;
        }
    }
    cout<<sum<<endl;
    return 0;
}

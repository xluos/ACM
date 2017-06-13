#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long  sum=0,minn=10000000009;
    cin>>n;
    while(n--)
    {
        int ans;
        scanf("%d",&ans);
        sum+=ans;
        if(sum<minn)
        {
            minn=sum;
        }
    }
    if(minn>=0)
        cout<<0<<endl;
    else
        cout<<-minn<<endl;
    return 0;
}

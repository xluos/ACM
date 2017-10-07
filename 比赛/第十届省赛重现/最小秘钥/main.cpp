#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[20010];
int main()
{
    int T;cin>>T;
    int ai[3010];
    while(T--)
    {
        int n,maxx=0;cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ai[i]);
        }
        for(int i=n;;i++)
        {
            int ans,j;
            memset(a,0,sizeof(a));
            for(j=0;j<n;j++)
            {
                ans=ai[j]%i;
                if(a[ans])
                    break;
                else
                    a[ans]=1;
            }
            if(j==n)
            {
                printf("%d\n",i);
                break;
            }
        }

    }
    return 0;
}

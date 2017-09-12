#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[105];
    while(scanf("%d",&n),n)
    {
        int k=0,ans=0,s;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            k=k^a[i];
        }
        if(k==0)
            printf("0\n");
        else
        {
            for(int i=0; i<n; i++)
            {
                s=k^a[i];
                if(s<a[i])
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

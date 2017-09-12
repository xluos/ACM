#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int w;
    while(cin>>w,w)
    {
        int a[1005],f[50005];
        memset(f,0,sizeof(f));
        int x,maxx=0;
        for(int i=0;i<w;i++)
        {
            scanf("%d",&a[i]);
            if(a[maxx]<a[i]){maxx=i;}
        }
        scanf("%d",&x);
        if(x>=5)
        {
            for(int i=0;i<w;i++)
                for(int j=x-5;j>=a[i];j--)
            {
                if(maxx==i)
                    continue;
                f[j]=max(f[j],f[j-a[i]]+a[i]);
            }
            printf("%d\n",x-f[x-5]-a[maxx]);
        }
        else
            printf("%d\n",x);
    }
    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int w;scanf("%d",&w);
    while(w--)
    {
        int num=0,ans,n,sum=0,minn=-0x3f3f3f3f,maxx=0;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ans);
            if(ans<0)
            {
                num++;
                if(minn<ans)
                    minn=ans;
            }
            sum+=ans;
            if(sum<0)sum=0;
            if(sum>maxx)maxx=sum;
        }
        if(num==n)
            printf("%d\n",minn);
        else
            printf("%d\n",maxx);
    }
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int w,a[10086];
    while(scanf("%d",&w),w)
    {
        int i,j,kt,k=0,jw,ans=0,maxx=-1,sum=0;
        memset(a,0,sizeof(a));
        for(i=0;i<w;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0)
                k++;
            sum+=a[i];
            if(sum<0)
            {
                ans=i+1;
                sum=0;
            }
            if(sum>maxx)
            {
                maxx=sum;
                kt=ans;
                jw=i;
            }
        }

        if(k==w)
            printf("0 %d %d\n",a[0],a[w-1]);
        else if(maxx==0)
                printf("0 0 0\n");
        else
            printf("%d %d %d\n",maxx,a[kt],a[jw]);
    }
    return 0;
}

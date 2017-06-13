#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w,n;
    int a[]={9,1,2,3,4,5,6,7,8};
    cin>>w;
    while(w--)
    {
        int sum=0,ans=0;
        scanf("%d",&n);
        for(int i=1;n>sum;i++)
        {
            ans=sum;
            sum+=i;
        }
        n=(n-ans)%9;
        printf("%d\n",a[n]);
    }

    return 0;
}































//    int n,k;
//    int a[]={1,1,2,1,2,3,
//    1,2,3,4,1,2,3,4,5,1,2,
//    3,4,5,6,1,2,3,4,5,6,7,
//    1,2,3,4,5,6,7,8};
//    cin>>n;
//    while(n--)
//    {
//        scanf("%d",&k);
//        if(k<37)
//            printf("%d\n",a[k-1]);
//        else
//            printf("%d\n",(k-36)%9+1);
//    }
//    return 0;

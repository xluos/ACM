#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w;
    while(scanf("%d",&w),w)
    {
        int min=0x3f3f3f3f,a[200],k;
        for(int i=0;i<w;i++)
        {
            cin>>a[i];
            if(a[i]<min)
            {
                min=a[i];
                k=i;
            }
        }
        int t=a[k];
        a[k]=a[0];
        a[0]=t;
        cout<<a[0];
        for(int i=1;i<w;i++)
            printf(" %d",a[i]);
        cout<<endl;
    }
    return 0;
}

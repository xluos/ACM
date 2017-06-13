#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxx(a,b) a>b?a:b;
using namespace std;

int main()
{
    int a[105][105],w;
    cin>>w;
    while(w--)
    {
        int n,i,j;
        cin>>n;
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
        for(i-=2;i>=0;i--)
            for(j=0;j<=i;j++)
                a[i][j]+=maxx(a[i+1][j],a[i+1][j+1]);
        printf("%d\n",a[0][0]);
    }
    return 0;
}

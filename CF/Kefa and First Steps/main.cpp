#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100005];
    int n,sum=1,maxx=0;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])
        {
            if(sum>maxx)
                maxx=sum;
            sum=1;
        }
        else
        {
            sum++;
        }
    }
    printf("%d\n",sum>maxx?sum:maxx);
    return 0;
}

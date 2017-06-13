#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10000000];
int main()
{
    int w;
    cin>>w;
    while(w--)
    {
        int n;cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        cout<<endl;
    }
    return 0;
}

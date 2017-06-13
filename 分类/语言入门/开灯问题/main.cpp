#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,k,a[1005]={0},t=1;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        for(int j=i;j<=n;j+=i)
            a[j]=(a[j]+1)%2;
    for(int i=1;i<=n;i++)
        if(a[i])
        {
            if(t){cout<<i;t=0;}
            else cout<<' '<<i;
        }
    printf("\n");
    return 0;
}

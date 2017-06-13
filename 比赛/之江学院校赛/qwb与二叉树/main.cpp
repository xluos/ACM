#include <iostream>
#include <bits/stdc++.h>
#define D 1000000007
using namespace std;
int a[55][55];
int main()
{
    memset(a,0,sizeof(a));
    a[1][1] = 1;
    for(int i=2;i<=55;i++)
    {
        for(int j= 1;j<=i;j++)
            a[i][j] = (a[i-1][j] + a[i-1][j-1])%D;
    }
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        if(m>(n+1)/2)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",a[n+1][m+1]%D);
    }
    return 0;
}

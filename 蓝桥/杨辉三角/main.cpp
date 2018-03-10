#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[40][40];
    memset(a,0,sizeof(a));
    cin>>n;
    a[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j<=i;j++)
        {
            a[i][j] = a[i-1][j-1]+a[i-1][j];
            printf("%d",a[i][j]);
            if(j!=i) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

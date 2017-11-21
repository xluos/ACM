#include <bits/stdc++.h>

using namespace std;
long  double f[1005];
int main()
{
    f[1]=f[2]=1;
    for(int i=3;i<1005;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    int m,n;
    cin>>n;
    while(n--)
    {
        cin>>m;
        printf("%.0llf\n",f[m]);
    }
    return 0;
}

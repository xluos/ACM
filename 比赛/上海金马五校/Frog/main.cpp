#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[3][100000];
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        memset(a,0,sizeof(a));
        a[0][1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                a[i%2][j]=a[i%2][j]+a[i%2][j-1];
                if(a[i%2][j]>1000000007)
                    a[i%2][j]%=1000000007;
                cout<<a[i%2][j];
            }
            cout<<endl;
        }
        int sum=0;
        for(int i=1;i<m;i++)
            sum+=a[(n-1)%2][i];
        cout<<sum<<endl;
    }
    return 0;
}

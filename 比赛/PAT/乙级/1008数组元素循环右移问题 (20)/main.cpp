#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,a[105];
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=n-(k%n);i<2*n-(k%n);i++)
    {
        printf("%d%c",a[i%n],i==2*n-(k%n)-1?'\n':' ');
    }
    return 0;
}

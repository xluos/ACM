#include <bits/stdc++.h>

using namespace std;
int a[1000005];
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m),n+m)
    {
        int ans,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&ans);
            if(binary_search(a,a+n,ans)) sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

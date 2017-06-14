#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c;
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if((a+b)>c)
            printf("Case #%d: true\n",i);
        else
            printf("Case #%d: false\n",i);
    }
    return 0;
}

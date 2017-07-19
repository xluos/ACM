#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,num=0;
    double sum=0,ans;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&ans);
        sum+=ans*(n-i)*(i+1);
    }
    printf("%.2lf\n",sum);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    double sum=0;
    cin>>n;n--;
    int maxx,ans;
    cin>>maxx;
    while(n--)
    {
        scanf("%d",&ans);
        if(ans<=maxx)
            sum++;
    }
    printf("%.0lf\n",floor(log(sum+1)/log(2.0)));
    return 0;
}

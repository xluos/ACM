#include <bits/stdc++.h>

using namespace std;

int main()
{
    double sum;
    int a[10004],n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    sum=a[0];
    for(int i=1;i<n;i++)
    {
        sum+=a[i];
        sum/=2;
    }
    printf("%d\n",(int)sum);
    return 0;
}

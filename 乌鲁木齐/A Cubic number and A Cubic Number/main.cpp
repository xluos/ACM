#include <bits/stdc++.h>

using namespace std;
int a[100000009];
int lifangcha(int a,int b)
{
    return (a-b)*(a*a+a*b+b*b);
}
int main()
{
    int t=0;
    for(int i=1;i<1001;i++)
    {
        for(int j=i+1;j<1001;j++)
        {
            a[t++] = lifangcha(j,i);
        }
    }
    sort(a,a+t);
    for(int i=0;i<100;i++)
        cout<<a[i]<<' ';
    int n,ans;
    cin>>n;
    while(n--)
    {
        scanf("%d",&ans);
    }
    return 0;
}

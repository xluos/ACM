#include <bits/stdc++.h>

using namespace std;
int judeg(int n)
{
    for(int i=2;i<sqrt(n)+1;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
void init(int a[],int n)
{
    int k=0;
    for(int i=2;i<=n+1;i++)
    {
        if(judeg(i)) a[k++]=i;
    }
}
int main()
{
    int n,a[10005],sum=0;
    cin>>n;
    init(a,n);
    for(int i=0;a[i+1]<=n;i++)
    {
        if(a[i+1]-a[i]==2) sum++;
    }
    cout<<sum<<endl;
    return 0;
}

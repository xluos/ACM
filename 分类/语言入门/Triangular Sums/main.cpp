#include <iostream>
#include <stdio.h>
using namespace std;
int t(int n)
{
    if(n==1)
        return 1;
    else return n+t(n-1);
}
int sum (int n)
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=i*t(i+1);
    }
    return sum;
}
int main()
{
    int w;cin>>w;
    for(int i=0;i<w;i++)
    {
        int n;cin>>n;
        cout<<i+1<<' '<<n<<' '<<sum(n)<<endl;
    }
    return 0;
}

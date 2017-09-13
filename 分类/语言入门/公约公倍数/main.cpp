#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a,int b)
{
    int n;
    if(a<b){n=a;a=b;b=n;}
    for(;n=a%b,n;a=b,b=n);
    return b;
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int a,b,n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        printf("%d %d\n",gcd(a,b),lcm(a,b));
    }

    return 0;
}

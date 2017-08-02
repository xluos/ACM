#include <bits/stdc++.h>

using namespace std;
int flag=0;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
double getf()
{
    double a,b;
    scanf("%lf/%lf",&a,&b);
    return a/b;
}
int out_huajian(int fz,int fm)
{
    int g=gcd(fz,fm);
    if(g==1)
    {
        if(flag) printf(" ");
        printf("%d/%d",fz/g,fm/g);
        flag=1;
    }
}
int main()
{
    double a,b;
    int k;
    a=getf();b=getf();
    if(a>b) swap(a,b);
    cin>>k;
    for(double i=0;i/k<b;i++)
    {
        if(i/k>a) out_huajian(i,k);
    }
    return 0;
}

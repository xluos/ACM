#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double len(double a)
{
    return sqrt(a*a-1);
}
bool cmp(double a,double b)
{
    return a>b;
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        double a[700];
        int n;cin>>n;
        for(int i=0;i<n;i++)
            scanf("%lf",&a[i]);
        sort(a,a+n,cmp);
        int num=0;
        double sum=0;
        for(;sum<20;num++)
        {
            sum+=len(a[num])*2;
        }
        cout<<num<<endl;
    }
    return 0;
}

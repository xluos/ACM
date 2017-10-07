#include <iostream>
#include <stdio.h>
using namespace std;
double nn(int x)
{
    double sum=1;
    for(int i=1;i<=x;i+=2)
        sum*=i;
    return sum;
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n;cin>>n;
        double sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=nn(i);
        }
        printf("%.0lf\n",sum);
    }
    return 0;
}

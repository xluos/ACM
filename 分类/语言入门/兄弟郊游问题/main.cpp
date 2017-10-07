#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double m,x,y,z;
    int w;cin>>w;
    while(w--)
    {
        cin>>m>>x>>y>>z;
        printf("%.2lf\n",(x*m*z)/(y-x));
    }

    return 0;
}

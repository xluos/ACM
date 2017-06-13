#include <iostream>
#include<stdio.h>
#define pi 3.1415926
using namespace std;

int main()
{

    double n;
    while(~scanf("%lf",&n))
    {
        printf("%.0f\n",n*n*n/3*4*pi);
    }
    return 0;
}

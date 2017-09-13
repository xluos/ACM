#include <bits/stdc++.h>

using namespace std;

int main()
{
    double r1,r2,p1,p2;
    cin>>r1>>p1>>r2>>p2;
    double A=(r1*r2)*cos(p1+p2),B=(r1*r2)*sin(p1+p2);
    if(abs(A)<0.01)A=0;
    if(abs(B)<0.01)B=0;
    printf("%.2lf%+.2lfi\n",A,B);
    return 0;
}

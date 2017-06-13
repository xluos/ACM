#include <iostream>
#include <stdio.h>
#include <math.h>
#define pi 3.1415926
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		double a;
		cin>>a;
		double r=a/sqrt(3);
		printf("%.2lf\n",pi*r*r);
}
    return 0;
}



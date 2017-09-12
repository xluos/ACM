#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
	double a,b,c,w;
	cin>>w;
	while(w--)
	{
		cin>>a>>b>>c;
		if(fabs(a+b-c)<=0.0001)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
    return 0;
}



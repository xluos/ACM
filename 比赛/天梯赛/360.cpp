#include <iostream>
#include <stdio.h>
#define nei(x) ((x-2)*180)/x
using namespace std;
int _360(int a,int b)
{

		if(360%a==0||360%b==0||360%(a+b)==0)
		return 1;
		return 0;
}
int main()
{
	int w;cin>>w;
	while(w--)
	{
		int a,b;
		cin>>a>>b;
		a=nei(a);
		b=nei(b);
		if(_360(a,b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
    return 0;
}



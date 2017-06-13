#include <iostream>
#include <stdio.h>
using namespace std;
int f(int a)
{
	int sum=0;
	while(a)
	{
		sum=sum*10+a%10;
		a/=10;
	}
	return sum;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<f(a)+f(b)<<endl;
	}
    return 0;
}



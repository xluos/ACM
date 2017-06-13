#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		char a,b;
		cin>>a>>b;
		if(a>b)cout<<a<<'<'<<b<<endl;
		if(a<b)cout<<a<<'>'<<b<<endl;
		if(a==b)cout<<a<<'='<<b<<endl;
	}
    return 0;
}



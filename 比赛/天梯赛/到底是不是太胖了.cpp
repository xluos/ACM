 #include <iostream>
#include <stdio.h>
using namespace std;
double abs(double n)
{
	if(n<0)n=-n;
	return n;
}
int main()
{
	double s,g,ans;
	int w;cin>>w;
	while(w--)
	{
		cin>>s>>g;
		s=(s-100)*0.9;
		g /=2;
		if(abs(s-g)<s*0.1)
			cout<<"You are wan mei!"<<endl;
		else if(g<s)
			cout<<"You are tai shou le!"<<endl;
		else if(g>s)
			cout<<"You are tai pang le!"<<endl;
	}
	return 0;
}


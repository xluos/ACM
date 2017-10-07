#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int s[500];
	int n;
	while(cin>>n)
	{
		if(!n)
		{
			cout<<0<<endl;
			continue;
		}
		int i=0;
		for(;n;i++)
		 {
		 	s[i]=n&1;
			n>>=1;
		 }
		 for(i--;i>=0;i--)
		 {
		 	cout<<s[i];
		 }
		 
		 cout<<endl;
	}
    return 0;
}



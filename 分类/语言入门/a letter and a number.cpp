#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		char ch;
		int n;
		cin>>ch>>n;
		if(ch>='A'&&ch<='Z')
			ch-='A'-1;
		if(ch>='a'&&ch<='z')
			ch=-(ch-'a'+1);
		cout<<n+ch<<endl;
	}
    return 0;
}



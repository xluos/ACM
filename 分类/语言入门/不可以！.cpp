#include <iostream>
#include <stdio.h>
#define X 0x80000000
using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a&&b)
		{
			if((a^b)>>31)
				cout<<"Signs are opposite"<<endl;
			else
				cout<<"Signs are not opposot"<<endl;
		}
		else
			cout<<"Signs can't be sure"<<endl;
	}
    return 0;
}



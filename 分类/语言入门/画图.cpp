#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int w;
	while(cin>>w)
	{
		for(int i=0;i<w;i++)
		{
			for(int j=0;j<w;j++)
			printf("*");
			cout<<endl;
		}
	}
    return 0;
}



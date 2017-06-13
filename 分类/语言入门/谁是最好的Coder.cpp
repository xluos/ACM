#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int w;
	while(cin>>w,w)
	{
		int a,b,max=-1;
		for(int i=0;i<w;i++)
		{
			cin>>a>>b;
			max=max<a+b?a+b:max;
		}
		cout<<max<<endl;
	}
	
    return 0;
}



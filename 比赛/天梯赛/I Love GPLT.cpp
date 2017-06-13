#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	char a[]={"I Love GPLT"};
	int l=strlen(a);
	for(int i=0;i<l;i++)
		cout<<a[i]<<endl;
	return 0;
}

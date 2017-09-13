#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char a[50];
	int w;cin>>w;
	getchar();
	while(w--)
	{
		gets(a);
		int l=strlen(a);
		for(int i=l-1;i>=0;i--)
		{
			if(a[i]>='0'&&a[i]<='9'||a[i]==' ')
			  continue;
			cout<<a[i];
		}
		cout<<endl;
	}
    return 0;
}



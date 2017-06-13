#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{

	char s[100],c=' ';
	int i=0,a,b;
	gets(s);
	for(i=a=0;s[i]!=' ';i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			a=-1;
			while(s[i]!=' ')i++;
			break;
		}
		a = a*10+s[i]-'0';
	}
	while(s[i]==' ')i++;
	if(a>0&&a<1001)cout<<a;
	else cout<<'?';
	cout<<" + ";
	for(b=0;s[i];i++)
	{
		if(s[i]<'0'||s[i]>'9')
		{
			b=-1;
			break;
		}
		b = b*10+s[i]-'0';
	}
	if(b>0&&b<1001)cout<<b;
	else cout<<'?';
	if(a<=0||b<=0||a>1000||b>1000)
	cout<<" = ?"<<endl;
	else
	cout<<" = "<<a+b<<endl;
	return 0;
}

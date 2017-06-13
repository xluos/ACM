#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int n;
	char c,s[100008];
	cin>>n>>c;
	getchar();
	gets(s);
	int l=strlen(s);
	for(int i=0;i<(n-l);i++)
		cout<<c;
	if(n>l)
	puts(s);
	else
	{
	for(int i=l-n;i<l;i++)
    cout<<s[i];
    cout<<endl;}
    return 0;
}



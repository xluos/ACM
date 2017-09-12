#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void _3fen(char s[],int k)
{
	char shu[105];
	int l=strlen(s),ls=0,i;
	if(k)shu[ls++]=')';
	for(i=l-1;i>l-4;i--)
		shu[ls++]=s[i];
	for(int j=0;i>=0;i--,j++)
	{
		if(j%3==0&&j>0)shu[ls++]=',';
		shu[ls++]=s[i];
	}
	if(k)
		printf("(");
	for(ls--;ls>=0;ls--)
	printf("%c",shu[ls]+48);
	printf("\n");
	
}
void strshu(char sh[],char s[])
{
	int i=0,j=0;
	if(sh[0]=='-')
		sh[0]='0';
	for(;sh[i]!='0';i++);
	for(;sh[i]!='.'&&sh[i];i++)
	{
		s[j++]=sh[i]-'0';
	}
	if(!sh[i])
	{
		s[j++]=-2;
		s[j++]=0;
		s[j++]=0;
		s[j++]=0;
	}
	else
	{
		s[j++]=sh[i++]-'0';
		s[j++]=sh[i++]-'0';
		s[j++]=sh[i++]-'0';
		s[j++]=sh[i++]-'0';
	}
	int k=j-1,ans;
	for(j--;s[j]>5;j--)
	{
		if(s[j]<0)j--;
		if(s[j-1]<0)ans=j-2;
		else ans=j-1;
		s[ans]=s[j]/10;
		s[j]%=10;
	}
	for(int i=0;i<k;i++)
	printf("%c",s[i]+48);
}
int main()
{
	double a;
	char s[105],shu[105];
	while(~scanf("%s",shu))
	{
		int k=0;
		if(shu[0]=='-')
			k=1;
		strshu(shu,s);
		_3fen(s,k);
	}
    return 0;
}



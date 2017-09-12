#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	string s;
	int w;cin>>w;
	while(w--)
	{
		map<string,int>mp;
		int n,sum=0;cin>>n;
		cin>>s;
		int l=s.size();
		for(int i=0;i<=l-n;i++)
		{
			if(mp[s.substr(i,n)]++)
				sum++;
		}
		cout<<sum<<endl;
	}
    return 0;
}
/*
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct xin
{
char a[12];
}r[123456];
bool cmp(xin a,xin b)
{
return strcmp(a.a,b.a)<0;
}
char s[124567];
int n;
void _strcpy(int x,int y)
{
int i=0;
for(i=0;i<n;i++)
r[x].a[i]=s[y++];
r[x].a[i]='\0';
// cout<<r[x].a<<endl;
}
int main()
{
int t,i;
int count=0;
cin>>t;
while(t--)
{
cin>>n>>s;
count=0;
int l=strlen(s);
for(i=0;i<=l-n;i++)
{
_strcpy(i,i);
}
sort(r,r+l-n+1,cmp);
for(i=0;i<l-n;i++)
{
//cout<<r[i].a<<endl;
if(strcmp(r[i].a,r[i+1].a)==0)
count++;
}
cout<<count<<endl;
}
}        */


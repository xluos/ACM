#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int abs(int a)
{
	return a<0?-a:a;
}
int zhen(char s[])
{
	if(s[0]-'0'>6)return 0;
	for(int i=2;i<6;i++)
	if(s[i]==s[i-1]&&s[i-1]==s[i-2])
	return 0;
	for(int i=1;i<6;i++)
	{
		if(s[i]-'0'>6)return 0;
		int ans=(s[i]-s[i-1]);
		if(abs(ans)>4)
		return 0;
	}
	return 1;
}
int main()
{
	int w;cin>>w;
	while(w--)
	{
		int a,b;
		char s[100];
		cin>>a>>b;
		for(int i=a;i<=b;i++)
		{
			sprintf(s,"%06d",i);
			if(zhen(s))
			printf("%s\n",s);
		}
		if(w)
		cout<<endl;

	}
    return 0;
}



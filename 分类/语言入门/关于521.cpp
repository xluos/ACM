#include <iostream>
#include <stdio.h>
#include <cstring>
#include<windows.h>
using namespace std;
int vis[1000005];
int _521(char s[])
{
	int f=0,yf=0,w=0,r=0,y=0;
	for(int i=0;s[i]&&w+r+y!=3;i++)
	{
		if(s[i]=='5')w=1;
		if(s[i]=='2')r=1;
		if(s[i]=='1')y=1;
	}
	if(w+r+y==3)f=1;
	for(int i=2;s[i];i++)
	{
		if(s[i]=='1'&&s[i-1]=='2'&&s[i-2]=='5')
		{
			yf=1;
			break;
		}
	}
	return f+yf;
}
int main()
{
	int a,b,t=1;
	char s[10];
	memset(vis,-1,sizeof(vis));
	LARGE_INTEGER lFrequency;
	QueryPerformanceFrequency(&lFrequency);
	while(cin>>a>>b)
	{
		int sum=0,ysum=0;
		LARGE_INTEGER lBeginCount;
		QueryPerformanceCounter(&lBeginCount);
		for(int i=a;i<=b;i++)
		{
			
			if(vis[i]==-1)
			{
				sprintf(s,"%03d",i);
				vis[i]=_521(s);
			}
			if(vis[i]>0)
				sum+=1;
			if(vis[i]==2)
				ysum+=1;
		}
		LARGE_INTEGER lEndCount;
		QueryPerformanceCounter(&lEndCount);
        printf("Case %d:%d %d\n",t++,sum,ysum);
        printf("ºÄ·ÑÊ±¼ä£º%lfºÁÃë \n",((double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart)*1000);
	}
    return 0;
}



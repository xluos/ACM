#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
struct list{
	int zhi,tail,abs;
};
int abs(int n)
{
	if(n<0)return -n;
	return n;
}
int vis[1000007];
int main()
{
	map<int,list>mp;
	map<int,int>m;
	list ans;
	int head,w,qhead;
	cin>>head>>w;
	for(int i=0;i<w;i++)
	{
		scanf("%d %d %d",&qhead,&ans.zhi,&ans.tail);
		ans.abs=abs(ans.zhi);
		mp[qhead]=ans;
	}
	int i;
	for(i=0;head!=-1;)
	{
		m[mp[head].abs]=1;
		if(m[mp[mp[head].tail].abs])
		{
			vis[i++]=mp[head].tail;
			mp[head].tail=mp[mp[head].tail].tail;
			continue;
		}
		if(mp[head].tail==-1)
			printf("%05d %d -1\n",head,mp[head].zhi);
		else
			printf("%05d %d %05d\n",head,mp[head].zhi,mp[head].tail);
		head=mp[head].tail;
	}
	for(int j=0;j<i-1;j++)
	{
		printf("%05d %d %05d\n",vis[j],mp[vis[j]].zhi,vis[j+1]);
	}
	if(i)
	printf("%05d %d -1\n",vis[i-1],mp[vis[i-1]].zhi);
	return 0;
}
/*

00100 5
99999 -15 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 15 23854
int main()
{
	int w,num;
	int mp[100000];
	memset(mp,0,sizeof(mp));
	cin>>num>>w;
	for(int i=0;i<w;i++)
	{
		cin>>lis[i].tou>>lis[i].zhi>>lis[i].wei;
		lis[i].abs=abs(lis[i].zhi);
		lis[i].vis=0;
	}
	int i,t;
	for(i=0,t=0;i+t<w;)
	{
		for(int j=0;j<w;j++)
		{
			if(lis[j].tou==num)
			{
				if(mp[lis[j].abs]==1)
				{
					ans2[t]=lis[j];
					ans2[t++].vis=1;
					ans[i-1].wei=lis[j].wei;
				}
				else
				{
					ans[i]=lis[j];
					ans[i].vis=1;
					mp[ans[i++].abs]=1;
				}
				num=lis[j].wei;
				break;
			}
		}
	}
	for(int ii=0;ii<i;ii++)
	{
		if(ii==i-1)
		printf("%05d %d -1\n",ans[ii].tou,ans[ii].zhi);
		else
		printf("%05d %d %05d\n",ans[ii].tou,ans[ii].zhi,ans[ii].wei);
	}
	for(int ii=0;ii<t;ii++)
	{
		if(ii==t-1)
		printf("%05d %d -1\n",ans2[ii].tou,ans2[ii].zhi);
		else
		printf("%05d %d %05d\n",ans2[ii].tou,ans2[ii].zhi,ans2[ii+1].tou);
	}
    return 0;
}*/



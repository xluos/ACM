#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		int n,ans,max=-1,maxs,t;
		map<int,int>mp;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ans);
			t=++mp[ans];
			if(max<t)
			{
				max=t;
				maxs=ans;
			}
		}
		cout<<maxs<<' '<<max<<endl;
	}
    return 0;
}



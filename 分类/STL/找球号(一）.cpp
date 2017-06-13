#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int n,m,ans;
	map<int,int>mp;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ans);
		mp[ans]=1;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&ans);
		if(mp[ans])
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}



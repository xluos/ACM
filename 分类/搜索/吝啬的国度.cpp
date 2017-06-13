#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		map<int,int>mp;
		int n,s,a,b;
		cin>>n>>s;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			mp[b]=a;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==s)
				cout<<-1;
			else
				printf("%d",mp[i]);
			if(i!=n)
			printf(" ");
			
		}
		cout<<endl;
	}
    return 0;
}



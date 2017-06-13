#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	map<int,int>mpsd;
	int s;
	int ans,w;cin>>w;
	while(w--)
	{
		int n;cin>>n;
		while(n--)
		{
			cin>>s;
			mpsd(s)++;
		}
	}
	cin>>w;int k=1;
	while(w--)
	{
		cin>>s;
		if(mpsd(s))
		{
			cout<<s<<" ";
			k=0;
		}
		mpsd(s)++;
	}
	if(k)cout<<"No one is handsome"<<endl;
	return 0;
}

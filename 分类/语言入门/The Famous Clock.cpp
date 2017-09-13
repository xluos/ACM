#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
string s[]={"I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII"};
int main()
{
	map<string,int>mp;
	for(int i=1;i<=12;i++)
	{
		mp[s[i-1]]=i;
	}
	string ans;
	int i=1;
	while(cin>>ans)
	{
		cout<<"Case "<<i++<<": "<<mp[ans]<<endl;
	}
    return 0;
}



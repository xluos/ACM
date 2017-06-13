#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
using namespace std;

int main()
{
	int w;cin>>w;
	getchar();
	while(w--)
	{
		char ch;
		map<char,int>mp;
		while(1)
		{
			scanf("%c",&ch);
			if(ch=='\n')break;
			mp[ch]++;
		}
		for(int i=0;i<mp['R'];i++)
		cout<<'R';
		for(int i=0;i<mp['W'];i++)
		cout<<'W';
		for(int i=0;i<mp['B'];i++)
		cout<<'B';
		cout<<endl;
	}
    return 0;
}



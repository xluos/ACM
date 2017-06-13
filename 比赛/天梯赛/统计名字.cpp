#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int main()
{
	map<string,int>name;
	int w;cin>>w;
	while(w--)
	{
		string na;
		char nam[50];
		int l,min=100;;
		scanf("%s",nam);
		//cin>>nam;
		sort(nam,nam+strlen(nam));
		na=nam;
		cout<<name[na]++<<endl;
	}
    return 0;
}



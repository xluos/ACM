#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		set<string> se;
		int n;cin>>n;
		string s;
		while(n--)
		{
			cin>>s;
			se.insert(s);
		}
		set<string>::iterator it=se.begin();
		cout<<*it<<endl;
	}
    return 0;
}



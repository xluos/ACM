#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
	return a.size()<b.size();
}
int main()
{
	int w,aa=1;
	while(cin>>w,w)
	{
		string a[100];
		int i;
		for(i=0;i<w;i++)
		cin>>a[i];
		sort(a,a+w,cmp);
		cout<<"SET "<<aa++<<endl;
		for(i=0;i<w;i+=2)
		cout<<a[i]<<endl;
		for(i-=w%2?3:1;i>=0;i-=2)
		cout<<a[i]<<endl;
	}
    return 0;
}



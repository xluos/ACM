#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	set<char>st;
	char s[16],ans[16],map[10];
	int i=0;
	cin>>s;
	for(int i=0;i<11;i++)
	{
		st.insert(s[i]);
	}
	cout<<"int[] arr = new int[]{";
	set<char>::reverse_iterator rit;
	rit=st.rbegin();
	cout<<*rit;
	ans[i++]=*rit;
	for(rit++;rit<st.rend();rit++)
	{
		cout<<','<<*rit;
		ans[i]=*rit;
		i++;
	}
	cout<<"};"<<endl;
	for(int i=0;ans[i];i++)
	{
		map[ans[i]]=i;
	}
	cout<<"int[] index = new int[]{";
	for(int i=0;i<11;i++)
	{
		if(i)
		cout<<map[s[i]];
		else
		cout<<','<<map[s[i]];
	}
	cout<<"};"<<endl;
	return 0;
}

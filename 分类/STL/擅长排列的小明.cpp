#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
using namespace std;
string str[]={
asd
asdasd
asdasdas
asd
asd
}
void qie(char *s,char *begin,char *end)
{
	for(;begin!=end;begin++)
	{
		*(s++)=*begin;
	}
	*s=0;
}
int main()
{
	int w;cin>>w;
	while(w--)
	{
		int n,m;
		char sh[]={"123456789"},s[10];
		set<string>se;
		cin>>n>>m;
		
		do
		{
			qie(s,sh,sh+m);
			se.insert(s);
		}while(next_permutation(sh,sh+n));
		for(set<string>::iterator it=se.begin();it!=se.end();it++)
		{
			cout<<*it<<endl;
		}
		
	}
    return 0;
}
/*#include <iostream>                  //µ›πÈ–¥∑®
#include <stdio.h>
using namespace std;
int n,m;
int vis[10]={0},p[10];
void pl(int q)
{
	if(q==m)
	{
		for(int j=0;j<m;j++)
			printf("%d",p[j]);
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[q]=i;
			pl(q+1);
			vis[i]=0;
		}
	}
}
int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		cin>>n>>m;
		pl(0);
	}
    return 0;
}

*/


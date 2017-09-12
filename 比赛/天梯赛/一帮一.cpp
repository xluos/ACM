#include <iostream>
#include <stdio.h>
using namespace std;
struct stm{
	string name;
	int sex,vis;
};
int main()
{
	int w;cin>>w;
	stm st[55];
	for(int i=0;i<w;i++)
	{
		cin>>st[i].sex>>st[i].name;
		st[i].vis=1;
	}
	for(int i=0;i<w/2;i++)
	{
		if(st[i].vis)
		{
			cout<<st[i].name<<' ';
			st[i].vis=0;
			for(int j=w-1;j>i;j--)
				if(st[j].vis&&(st[j].sex+1)%2==st[i].sex)
				{
					cout<<st[j].name<<endl;
					st[j].vis=0;
					break;
				}
		}
	}
	return 0;
}













/*#include <iostream>
#include <stdio.h>
using namespace std;
bool cmp(stm a,stm b)
{
	if(a.sex==b.sex)
	return a.num<b.num;
	else
	return a.sex<b.sex;
}
struct stm{
	string name;
	int sex,num;
};
int main()
{
	int w;cin>>w;
	stm st[55];
	for(int i=0;i<w;i++)
	{
		cin>>st[i].sex>>st[i].name;
		st[i].num=i+1;
	}
	int vis=st[0].sex;
	w /=2;
	sort(st,st+w,cmp);
	for(int i=0;i<w;i++)
	{
		
	}
	return 0;
}*/

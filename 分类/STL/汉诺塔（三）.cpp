#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	int w;cin>>w;
	stack<int>sp[4];
	while(w--)
	{
		int p,q,k=0,a,b,ans_a,ans_b;
		cin>>p>>q;
		for(int i=0;i<4;i++)
		sp[i].push(0);
		while(p)
			sp[1].push(p--);
		while(q--)
		{
			cin>>a>>b;
			ans_a=sp[a].top();
			ans_b=sp[b].top();
			if(ans_a>ans_b&&ans_b!=0)
			{
				k=1;
				continue;
			}
			else if(ans_a==0)
			{
				k=1;
			}
			sp[a].pop();
			sp[b].push(ans_a);
		}
		if(k)
			cout<<"illegal"<<endl;
		else
			cout<<"legal"<<endl;
	}
    return 0;
}



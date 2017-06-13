#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		priority_queue<double,vector<double>, greater<double> >q;
		int n,vis=1;;cin>>n;
		double t=0,k=0,sum=0;
		//if((n+1)%2)q.push(0);
		while(n--)
		{
			int ans;
			cin>>ans;
			q.push(ans);
		}
		while(q.size()!=1)
		{
			vis=0;
			t=q.top();q.pop();
			k=q.top();q.pop();
			sum+=k+t;
			q.push(k+t);
		}
		if(vis)
		{
			printf("%.0lf\n",q.top());
		}
		else
			printf("%.0lf\n",sum);
	}
    return 0;
}



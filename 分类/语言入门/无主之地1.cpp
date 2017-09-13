#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,m,t=0,a[104]={0},b[104]={0};
	while(cin>>n>>m,n+m)
	{
		if(a[n]==0)
			b[t++]=n;
		a[n]+=m;
	}
	for(int i=0;i<t;i++)
	{
		cout<<b[i]<<' '<<a[b[i]]<<endl;
	}
    return 0;
}



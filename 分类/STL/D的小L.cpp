#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int vis[10]={0},p[10];
void pl(int q)
{
	if(q==n)
	{
		for(int j=0;j<n;j++)
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
		cin>>n;
		pl(0);
	}
    return 0;
}



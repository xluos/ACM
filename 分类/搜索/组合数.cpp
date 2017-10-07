#include <iostream>
#include <stdio.h>
using namespace std;
int n,m;
int a[]={10,1,2,3,4,5,6,7,8,9},
	vis[10]={0};
void zuhe(int k)
{
	if(k==m+1)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<a[i];
		}
		cout<<endl;
		return ;
	}
	for(int i=n;i>0;i--)
	{
		if(!vis[i]&&i<a[k-1])
		{
			vis[i]=1;
			a[k++]=i;
			zuhe(k);
			k--;
			vis[i]=0;
			
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		zuhe(1);
	}
    return 0;
}



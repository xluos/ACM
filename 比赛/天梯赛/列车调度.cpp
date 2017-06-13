#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 100005
using namespace std;
int _2fen(int n[],int l,int a)
{
	int mid,head=0,tail=l-1;
	while(head<=tail)
	{
		mid=(head+tail)/2;
		if(n[mid]<a)
			head=mid+1;
		else if(n[mid]>a)
			tail=mid-1;
		else
			return mid;
	}
	return head;
}
int lis(int a[],int n)
{
	int vis[N],k=1;
	vis[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<vis[k-1])
		{
			vis[k++]=a[i];
		}
		else
		{
			int mid=_2fen(vis,k,a[i]);
			vis[mid]=a[i];
		}
	}
	return k;
}
int main()
{
	int w,x[N];   //LIS  最长递增子序列   O（Nlongn）
	cin>>w;
	for(int i=0;i<w;i++)
	{
		cin>>x[i];
	}
	cout<<lis(x,w)<<endl;
	return 0;
}
/*int main()                //动态规划解法  O（N~2）
{
	int w,x[N],l[N],max=0;
	cin>>w;
	for(int i=0;i<w;i++)
	{
		cin>>x[i];
		l[i]=1;
	}
	for(int i=1;i<w;i++)
		for(int j=0;j<i;j++)
		{
			if(x[j]<x[i]&&l[i]<=l[j])
			{
				l[i]=l[j]+1;
				if(max<l[i])max=l[i];
			}
		}
	cout<<max<<endl;
}*/


/*int c[2][N];
int main()                     //最长公共子序列解法
{
	int w,x[N],y[N];
	cin>>w;
	memset(c,0,sizeof(c));
	for(int i=1;i<=w;i++)
	{
		cin>>x[i];
		y[i]=x[i];
	}
	sort(y,y+w+1);
	for(int i=1;i<=w;i++)
		for(int j=1;j<=w;j++)
		{
			if(x[i]==y[j])
				c[i%2][j]=c[(i+1)%2][j-1]+1;
			else
				c[i%2][j]=max(c[(i+1)%2][j],c[i%2][j-1]);
		}
	cout<<c[w%2][w]<<endl;

}*/

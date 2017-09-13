#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int sum;
void dfs(int n)
{
	if(n==39)
	{
		sum++;
		cout<<sum<<' ';
		return;
	}
	if(n>39)return;
	dfs(n+1);
	dfs(n+2);
	return;
}
int main()
{
	sum=0;
	dfs(0);
	cout<<sum<<endl;
	return 0;
}


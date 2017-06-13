#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
bool sushu(int n)
{
	if(n==2)return true;
	if(!(n%2)||n==1)return false;
	int m=sqrt((double)n)+1;
	for(int i=2;i<m;i++)
	{
		if(!(n%i))return false;
	}
	return true;
}
int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		int n;
		cin>>n;
		if(sushu(n))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}

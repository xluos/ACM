#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int mod(int j,int a[],int n)
{

	for(int i=0;i<n;i++)
	{
		j%=a[i];
	}
	return j;
}
int main()
{
	int A[100006],f[100006],w;
	cin>>w;
	while(w--)
	{
		memset(f,-1,sizeof(f));
		int n,m,a,b,sum;cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			sum=0;
			scanf("%d %d",&a,&b);
			for(int j=a;j<=b;j++)
			{
				if(f[j]==-1)
					f[j]=mod(j,A,n);
				sum+=f[j];
			}
			cout<<sum<<endl;
		}
	
		
	}
	

    return 0;
}



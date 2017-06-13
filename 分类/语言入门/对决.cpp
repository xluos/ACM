#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n,k;
	while(cin>>n>>k,n+k)
	{
		int max=ceil(n/2.0)*(n/2),min=n-1,ans=0;
		if(k>=min&&k<=max)
		{
			for(int j=1;j<=n/2;j++)
			{
				ans=(n-j)*j;
				if(ans==k)
				{
		 			cout<<"YES"<<endl;
					goto go;
				}
			}
			
		}
		cout<<"NO"<<endl;
		go:;
	}
    return 0;
}



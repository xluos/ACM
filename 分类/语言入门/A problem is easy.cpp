#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		int i,j,n,m,sum=0;cin>>n;
		/*for(i=1;i<=sqrt(n);i++)
			for(j=i;j<=sqrt(n);j++)
			{
				if(j*i+j+i==n)
				sum++;
				break;
			}
		cout<<sum<<endl;*/
		m=sqrt(n+1);
		for(i=2;i<=m;i++)
		{
			if(((n+1)%i)==0)
				sum++;
		}
		cout<<sum<<endl;
	}
    return 0;
}



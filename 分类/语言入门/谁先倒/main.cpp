#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int j,y,n,jhan,jhua,yhan,yhua,a,b;
	cin>>j>>y;
	a=j;b=y;
	cin>>n;
	while(n--)
	{
		cin>>jhan>>jhua>>yhan>>yhua;
		int sum=jhan+yhan;
		if((jhua==sum)&&(yhua==sum))
			continue;
		if(jhua==sum)
			j--;
		if(yhua==sum)
			y--;
		if(j==0)
		{
			printf("A\n%d\n",b-y);
			break;
		}
		if(y==0)
		{
			printf("B\n%d\n",a-j);
			break;
		}
	}

	return 0;

}


#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n,k;
	while(~scanf("%d %d",&n,&k))
	{
		if(k>=n)
		{
			printf("2\n");
			continue;
		}
		printf("%d\n",int(2+ceil((n-k)*1.0/k*2)));
	}
    return 0;
}



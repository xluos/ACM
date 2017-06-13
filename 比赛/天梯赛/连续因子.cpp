#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i,j,sum,max=0,ans=1;
	cin>>sum;
	for(i=j=2;i<12;i++)
	{
		ans *= i;
		if(ans>sum)
		{
			ans /= j;
			j++;
			//max--;
		}
		if(!(sum%ans))
		{
			max++;
		}
	}
	cout<<max<<endl;
    return 0;
}



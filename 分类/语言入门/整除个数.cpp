#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	double n,a;
	while(cin>>n>>a)//���������k*b<=N  ��k<=n/b;
	{
		/*int sum=0,ans=a;
		for(;a<=n;a+=ans)
			sum++;
		cout<<sum<<endl;*/
		cout<<(int)(n/a)<<endl;
	}
    return 0;
}



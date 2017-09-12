#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int w;cin>>w;
	while(w--)
	{
		int n,sum=1;cin>>n;
		if(n<=10){
			cout<<1<<endl;
			continue;
		}
		n=ceil((n-10)/5.0);
		sum += n;
		cout<<sum<<endl;
	}
    return 0;
}



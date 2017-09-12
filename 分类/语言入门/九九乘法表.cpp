#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int w;
	cin>>w;
	while(w--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
	
			for(int j=i;j<10;j++)
				printf("%d*%d=%d ",i,j,i*j);
		cout<<endl;
		
		}if(w)cout<<endl;
		
	}
    return 0;
}



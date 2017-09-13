#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int j,y,w,a,b;
	cin>>j>>y>>w;
	a=j;b=y;
	while(w--)
	{
		int jhan,jhua,yhan,yhua;
		cin>>jhan>>jhua>>yhan>>yhua;
		int sum=jhan+yhan;
		if(jhua==sum&&sum==yhua)continue;
		if(jhua==sum)j--;
		if(yhua==sum)y--;
		if(j<0){
            cout<<'A'<<endl<<b-y<<endl;
            break;
		}
		if(y<0){
            cout<<'B'<<endl<<a-j<<endl;
            break;
		}
		
	}
	return 0;
}

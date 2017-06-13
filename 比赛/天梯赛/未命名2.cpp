#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int a,ans[]={7,1,2,3,4,5,6};
	cin>>a;
	cout<<ans[(a+2)%7]<<endl;
}

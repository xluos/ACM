#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int a[]={4,10,22,46,94,190,382,766,
	1534,3070,6142,12286,24574,49150,98302,
	196606,393214,786430,1572862,3145726,
	6291454,12582910,25165822,50331646,100663294,
	201326590,402653182,805306366,
	1610612734,3221225470};
	int w;cin>>w;
	while(w--)
	{
		int ans;
		cin>>ans;
		cout<<a[ans-1]<<endl;
	}
}

/*int N;
void chitao(double n,double m)
{
	m=m*2+2;
	if(n==N){
		printf("%.0lf\n",m);
		return ;
	}

	chitao(n+1,m);

}
int main()
{
	int w;cin>>w;
	while(w--)
	{
  		cin>>N;
		chitao(1,1);
	}
    return 0;
}*/




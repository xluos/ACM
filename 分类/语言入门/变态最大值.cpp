#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int mymax(int a,int b,int c,int d)
{
	if(d)
		return max(a,max(b,c));
	else
		return min(a,min(c,b));
}
int main()
{
	int w;
	while(cin>>w)
	{
		int maxx=-1,a,b,c,d=1;
		while(w)
		{
			w-=3;
			scanf("%d %d %d",&a,&b,&c);
			int ans=mymax(a,b,c,d);
			maxx=maxx<ans?ans:maxx;
			d=1-d;
		}
		cout<<maxx<<endl;
	}
    return 0;
}



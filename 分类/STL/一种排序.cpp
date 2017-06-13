#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct changfx{
	int id;
	int c,k;
};
void huan(int* a,int* b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int cmp(changfx a,changfx b)
{
	if(a.id==b.id)
		if(a.c==b.c)
			return a.k<b.k;
		else
			return a.c<b.c;
	else
	return a.id<b.id;
}
int main()
{
	changfx c[1008];
	int w;cin>>w;
	while(w--)
	{
		int n;
		int a,b;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>c[i].id>>a>>b;
			if(a<b)huan(&a,&b);
			c[i].c=a;c[i].k=b;
		}
		sort(c,c+n,cmp);
		printf("%d %d %d\n",c[0].id,c[0].c,c[0].k);
		for(int i=1;i<n;i++)
		{
			if(c[i].id==c[i-1].id&&c[i].c==c[i-1].c&&c[i].k==c[i-1].k)
				continue;
			printf("%d %d %d\n",c[i].id,c[i].c,c[i].k);
		}
	}
    return 0;
}



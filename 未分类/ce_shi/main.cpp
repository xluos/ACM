#include<stdio.h>
#include<math.h>
int main()
{
	int o,u,i,p,m,n,y,z,l,x;
	scanf("%d",&o);
	while(o--)
	{
		scanf("%d",&u);

		l=0;
		for(p=u-1;p>=1;p--)
		{
			x=sqrt(p);
			for(i=2;i<=x;i++)
			{
				if(p%i==0)      //求小于u的最大素数
					break;
				if(i==x)
					l=1;
			}
			if(l==1)
				break;
		}
		m=p;
		y=u-m;

		l=0;
		for(p=u+1;p>1;p++)
		{
			x=sqrt(p);
			for(i=2;i<=x;i++)
			{
				if(p%i==0)
					break;       //求大于u的最小素数
				if(i==x)
					l=1;
			}
			if(l==1)
				break;
		}
		n=p;
		z=n-u;

		if(y<=z)
			printf("%d %d\n",m,y);
		if(z<y)
			printf("%d %d\n",n,z);
	}
	return 0;
}

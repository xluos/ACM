#include<stdio.h>
#include<math.h>
//7 4 1 5 1 6 4 3 7 5 2 3 6 2
int vis[] = {0,0,0,0,1,0,0,1,0,0};
int arr[] = {7,4,0,0,0,0,4,0,7,0,0,0,0,0};
void getnumarr(int n)
{
	if(n==13&&arr[n])
	{
		for(int i=0;i<14;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	if(!arr[n])
	{
		for(int i=1;i<8;i++)
		{
			if(!vis[i]&&!arr[n+i+1])
			{
				vis[i] = 1;
				arr[n] = arr[n+i+1] = i;
				getnumarr(n+1);
				vis[i] = 0;
				arr[n] = arr[n+i+1] = 0;
			}
		}
	}
	else
	{
		getnumarr(n+1);
	}
}
int main()
{
	
	getnumarr(2);
	return 0;
}

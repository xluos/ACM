#include <stdio.h>
char a[15]; 
int count=0,h=9,j=5,sum =2;
void dfs(int n)
{
	if(n==14)
	{
		if(sum == 1){
			count++;
		for(int i=13;i>0;i--) printf("%c ",a[i]);
		printf("b\n");
		}
		return ;
	}
	if(h>0&&sum>0)
	{
		h--;
		a[j+h] = 'b';
		sum -= 1;
		dfs(n+1);
		sum += 1;
		h++;
	}
	if(j>0)
	{
		j--;
		a[j+h] = 'a';
		sum <<= 1;
		dfs(n+1);
		sum >>= 1;
		j++;
	}
}

int main()
{
	dfs(0);
	printf("%d\n",count);
} 

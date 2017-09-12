#include<stdio.h>
int main()
{
    int i,n,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        sum+=i;
    printf("%d\n",sum);
}





/*int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		printf(" ");
		for(j=0;j<i;j++)
		printf("*");
		printf("\r");
	}
	return 0;

}
*/

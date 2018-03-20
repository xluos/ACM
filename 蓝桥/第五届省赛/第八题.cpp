#include<stdio.h>
#include<queue>

using namespace std;
struct Node {
	int i, n;
}q,p;
int ant[51][105], vis[51], ort[51]; 
int N;
int next(int i,int n)
{
	int ans = ant[i][n - 1] + ort[i];
	if(ans < 0 || ans > 100)
	{
		ant[i][n] = -1;
		return 0;
	}
	ant[i][n] = ans;
	return 1;
}
void getAntPath(int i)
{
	int n = 1;
	while(next(i,n)) n++;
}
void getOrt(int i)
{
	if(ant[i][0]<0)
	{
		ant[i][0] = -ant[i][0];
		ort[i] = -1;
	}
	else
	{
		ort[i] = 1;
	}
}
void outAntPath(int i)
{
	for(int j=0;ant[i][j]>0;j++)
	{
		printf("%d ",ant[i][j]);
	}
	printf("\n");
}
int getSickAntNumber(int i, int n)
{
	int count = 1;
	queue<Node>Q;
	Node q,p;
	q.i = i;
	q.n = n;
	Q.push(q);
	while(!Q.empty())
	{
		q = Q.front();
		Q.pop();
		int i = q.i;
		for(int j = q.n;ant[i][j] != -1; j++)
		{
			//printf("%d时刻%d蚂蚁位置在%d\n",j,i,ant[i][j]);
			for(int k=0;k < N;k++)
			{
			//	printf("k == %d n == %d\n",k,N);
			//	printf("%d时刻%d蚂蚁位置在%d\n",j,k,ant[k][j]);
				if(k != i && !vis[k] && (ant[k][j] == ant[i][j] - ort[i] || ant[k][j] == ant[i][j]) && ant[k][j] != 0)
				{
					//printf("%d时刻%d蚂蚁和%d蚂蚁相遇，位置在%d %d\n",j,i,k,ant[i][j],ant[k][j]);
					p.i = k;
					p.n = j;
					vis[k] = 1;
					Q.push(p);
					count++;
				}
			}
		}
	}
	return count;
}
int main()
{

	scanf("%d",&N);
	scanf("%d",&ant[0][0]);
	getOrt(0);
	vis[0] = 1;
	getAntPath(0);
	for(int i=1;i<N;i++)
	{
		scanf("%d",&ant[i][0]);
		getOrt(i);
		getAntPath(i);
		//outAntPath(i);
	}
	printf("%d\n",getSickAntNumber(0,1));
	
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<windows.h>
#define Time_init	LARGE_INTEGER lFrequency; \
					QueryPerformanceFrequency(&lFrequency);
#define Time_begin	LARGE_INTEGER lBeginCount; \
					QueryPerformanceCounter(&lBeginCount);
#define Time_end	LARGE_INTEGER lEndCount; \
					QueryPerformanceCounter(&lEndCount);
#define Time_out	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart; \
					printf("运行时间%lf毫秒",time*1000);
const int N = 10;
int vis[N][N][N], vis2[N][N], chara[N][N];
int ok = 0;
int getblock(int i,int j)
{
	return (i/3)*3 + (j/3);
}
void updata(int i,int j,int n,int flag)
{
	for(int k=0;k<9;k++)
	{
		vis[k][j][n] += flag;
		vis[i][k][n] += flag;		
	}
	vis2[getblock(i,j)][n] += flag;
}
int get_i(int n)
{
	return n/9;
}
int get_j(int n)
{
	return n%9;
}
void getAnswer(int n)
{
	
	
	int i = get_i(n);
	int j = get_j(n);
	if(n==81)
	{
		for(int i=0;i<9;i++) 
		{ 
			for(int j=0;j<9;j++)
			{
				printf("%d ",chara[i][j]);
			}
			printf("\n");
		}
		ok = 1;
		return ;
	}
	if(!chara[i][j])
	{
		for(int k=1;k<10;k++)
		{
			if(!vis[i][j][k]&&!vis2[getblock(i,j)][k])
			{
				chara[i][j] = k;
				updata(i,j,k,1);
				getAnswer(n+1);
				if(ok) return ;
				updata(i,j,k,-1);
				chara[i][j] = 0;
			}
		}
	}
	else
	{
		getAnswer(n+1);
	}
	return ;
}
int main()
{
	//Time_init 
	char ch;
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		memset(chara,0,sizeof(chara));
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		ok = 0; 
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				//scanf("%c",&ch);
				//chara[i][j] = ch - '0';
				//updata(i,j,ch-'0',1);
				scanf("%d",&chara[i][j]);
				updata(i,j,chara[i][j],1);
			}
			//getchar();
		}
		//Time_begin;
		getAnswer(0);
		//Time_end;
		//Time_out;
	}
	return 0;
}

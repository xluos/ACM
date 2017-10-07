/**

方格填数

如下的10个格子
   +--+--+--+
   |  |  |  |
+--+--+--+--+
|  |  |  |  |
+--+--+--+--+
|  |  |  |
+--+--+--+

（如果显示有问题，也可以参看【图1.jpg】）

填入0~9的数字。要求：连续的两个数字不能相邻。
（左右、上下、对角都算相邻）

一共有多少种可能的填数方案？

请填写表示方案数目的整数。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。*/
#include <bits/stdc++.h>

using namespace std;
int Map[3][4],vis[3][4],num[15];
int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int c,s;
bool check(int x1,int y1,int n)
{
	for(int i=0;i<8;i++)
	{
		int xx=x1+dir[i][0];
		int yy=y1+dir[i][1];
		if(xx>=0&&xx<3&&yy>=0&&yy<4)
		{
			if(abs(n-Map[xx][yy])==1)
				return false;
		}
	}
	return true;

}
void dfs(int x,int y)
{
    s++;
    if(s>12)return ;
	if(x==2&&y==3)
	{
		c++;
		return ;
	}
	for(int i=0;i<=9;i++)
	{
		if(num[i]==0)
		{
			if(check(x,y,i))
			{
				num[i]=1;
				Map[x][y]=i;
				cout<<i<<" ";
				dfs(s/4,s%4);
				Map[x][y]=-2;
				num[i]=0;
			}
		}
	}

	return ;
}
int main()
{
	c=0;s=1;
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	memset(Map,1,sizeof(Map));
	vis[0][0]=1;vis[2][3]=1;
	dfs(0,0);
	//int sum=dfs(0,1);
	cout<<endl<<c<<endl;
	return 0;
}

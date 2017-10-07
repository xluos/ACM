#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int Chart[N][N],vis[N][N],X,Y;
int n,m,q1,q2;
int dir[][2] = {0,1,0,-1,1,0,-1,0};
struct node
{
	int x,y;
	int Direction,num;
};
bool judge(node p)
{
	if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m || Chart[p.x][p.y] != 0)
        return false;
    return true;
}
void BFS(int x,int y)
{
	node q,p;
	queue<node>Q;
	q.x = x;
	q.y = y;
	q.Direction = -1;
	q.num = 0;
	Q.push(q);
	while (!Q.empty())
	{
		q = Q.front();
		//cout<<q.x<<' '<<q.y<<' '<<q.num<<endl;
		Q.pop();
		for (int i=0; i<4; i++)
		{
			p.x = q.x + dir[i][0];
			p.y = q.y + dir[i][1];
			if (q.Direction != i)
			{
				p.Direction = i;
				p.num = q.num + 1;
			}
			else
			{
				p.Direction = q.Direction;
				p.num = q.num ;
			}
			if (p.x == X && p.y == Y && p.num < 4)
			{
				printf("YES\n");
				return ;
			}
			if (!vis[p.x][p.y]&&p.num<4&&judge(p))
			{
			    vis[p.x][p.y] = 1;
                Q.push(p);
			}
		}
	}
	printf("NO\n");
	return ;
}
int main()
{
	while (scanf("%d %d",&n,&m),n+m)
	{
	    memset(Chart,0,sizeof(Chart));
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				scanf("%d",&Chart[i][j]);
			}
		}
		int w;
		scanf("%d",&w);
		while (w--)
		{
		    memset(vis,0,sizeof(vis));
			scanf("%d %d %d %d",&q1,&q2,&X,&Y);
			q1--; q2--;X--;Y--;
			if (Chart[q1][q2] != Chart[X][Y]||(Chart[q1][q2]==0&&Chart[q1][q2] == Chart[X][Y])) printf("NO\n");
			else BFS(q1,q2);
		}

	}
	return 0;
}

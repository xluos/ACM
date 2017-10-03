#include <bits/stdc++.h>

using namespace std;
const int N = 105;
char Chart[N][N];
int vis[N][N],X,Y;
int n,m,q1,q2,k;
int dir[][2] = {0,1,1,0,0,-1,-1,0};
struct node
{
	int x,y;
	int Direction,num;
};
bool judge(node p)
{
	if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m || Chart[p.x][p.y] == '*')
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
	q.num = -1;
	vis[x][y] = 1;
	Q.push(q);
	while (!Q.empty())
	{
		q = Q.front();
		//cout<<q.x<<' '<<q.y<<' '<<q.num<<' '<<Chart[q.x][q.y]<<endl;
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
			if (p.x == X && p.y == Y && p.num <= k)
			{
				printf("yes\n");
				return ;
			}
			if (vis[p.x][p.y]>p.num&&p.num<=k&&judge(p))
			{
			    vis[p.x][p.y] = p.num;
                Q.push(p);
			}
		}
	}
	printf("no\n");
	return ;
}
int main()
{
    int w;
    scanf("%d",&w);
    while(w--)
    {
        memset(vis,0x3f,sizeof(vis));
        scanf("%d %d",&n,&m);
		for (int i=0; i<n; i++)
		{
            scanf("%s",&Chart[i]);
		}
		scanf("%d %d %d %d %d",&k,&q2,&q1,&Y,&X);
		q1--;q2--;X--;Y--;
		if(Chart[q1][q2] == '*'||Chart[X][Y] == '*') printf("no\n");
		else if(q1 == X&&q2 == Y) printf("yes\n");
		else BFS(q1,q2);
    }

	return 0;
}

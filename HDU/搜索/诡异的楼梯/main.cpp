#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x, y, step;
};
int n, m;
char map[30][30];
int vist[30][30];
int xx, yy;
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int check(int x, int y)
{
	if (x<1 || y<1 || x>n || y>m)
		return 0;
	if (map[x][y] == '*')
		return 0;
	if (vist[x][y])
		return 0;
	return 1;
}
int bfs(int x1, int y1)
{
	queue<node> q;
	node temp;
	temp.x = x1;
	temp.y = y1;
	temp.step = 0;
	memset(vist, 0, sizeof(vist));
	vist[temp.x][temp.y] = 1;
	q.push(temp);
	node t, p;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (map[p.x][p.y] == 'T')
			return p.step;
		for (int i = 0; i < 4; i++)
		{
			int nx = p.x + dir[i][0];
			int ny = p.y + dir[i][1];
			if (nx<1 || ny<1 || nx>n || ny>m) //±ß½ç
				continue;
			if (vist[nx][ny] || map[nx][ny] == '*')
				continue;
			else if (map[nx][ny] == '.' || map[nx][ny] == 'T')
			{
				t.x = nx;
				t.y = ny;
				t.step = p.step + 1;
				q.push(t);
				vist[t.x][t.y] = 1;
			}
			else
			{
				if (i == 0 || i == 1)
				{
					if (map[nx][ny] == '|'&&p.step % 2 == 1)
					{
						nx = nx + dir[i][0];
						ny = ny + dir[i][1];
						if (check(nx, ny))
						{
							t.x = nx;
							t.y = ny;
							t.step = p.step + 1;
							q.push(t);
							vist[t.x][t.y] = 1;
						}
					}
					else if (map[nx][ny] == '-'&&p.step % 2 == 0)
					{
						nx = nx + dir[i][0];
						ny = ny + dir[i][1];
						if (check(nx, ny))
						{
							t.x = nx;
							t.y = ny;
							t.step = p.step + 1;
							q.push(t);
							vist[t.x][t.y] = 1;
						}
					}
					else
					{
						t.x = p.x;
						t.y = p.y;
						t.step = p.step + 1;
						vist[t.x][t.y] = 1;
						q.push(t);
					}

				}
				else //if (i == 2 || i == 3)
				{
					if (map[nx][ny] == '|'&&p.step % 2 == 0)
					{
						nx = nx + dir[i][0];
						ny = ny + dir[i][1];
						if (check(nx, ny))
						{
							t.x = nx;
							t.y = ny;
							t.step = p.step + 1;
							q.push(t);
							vist[t.x][t.y] = 1;
						}
					}
					else if (map[nx][ny] == '-'&&p.step % 2 == 1)
					{
						nx = nx + dir[i][0];
						ny = ny + dir[i][1];
						if (check(nx, ny))
						{
							t.x = nx;
							t.y = ny;
							t.step = p.step + 1;
							q.push(t);
							vist[t.x][t.y] = 1;
						}
					}
					else
					{
						t.x = p.x;
						t.y = p.y;
						t.step = p.step + 1;
						vist[t.x][t.y] = 1;
						q.push(t);
					}
				}

			}

		}
	}
	return -1;
}
int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		int i, j;
		for (i = 1; i <= n; i++)
		{
			getchar();
			for (j = 1; j <= m; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == 'S')
				{
					xx = i;
					yy = j;
				}
			}
		}
		//cout << xx << " " << yy << endl;
		int ans = bfs(xx, yy);
		cout << ans  << endl;
	}
	return 0;
}
/*
||||T
|||||
|||||
|||||
||||S


*/

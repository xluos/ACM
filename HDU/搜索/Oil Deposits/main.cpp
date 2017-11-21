#include <bits/stdc++.h>

using namespace std;

int n,m;
int dir[8][2]={0,1,0,-1,1,0,1,1,1,-1,-1,0,-1,1,-1,-1};
char Chart[105][105];
void DFS(int x,int y)
{
    if(Chart[x][y] == '@') Chart[x][y] = '*';
    for(int i = 0;i < 8; i++)
    {
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        if(X >= 0&&X < n&&Y >= 0&&Y < m&&Chart[X][Y] == '@')
        {
            DFS(X,Y);
        }
    }
}
int main()
{
    while(~scanf("%d %d",&n,&m),n+m)
    {
        int count = 0;
        for(int i = 0;i < n; i++)
        {
            scanf("%s",Chart[i]);
        }
        for(int i = 0;i < n; i++)
        {
            for(int j = 0;j < m ; j++)
            {
                if(Chart[i][j] == '@')
                {
                    DFS(i,j);
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

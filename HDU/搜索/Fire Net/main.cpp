#include <bits/stdc++.h>

using namespace std;
const int MAX = 11;
char Chart[MAX][MAX];
int maxx,n;
int judge(int x,int y)
{
    if(Chart[x][y] != '.') return 0;
    for(int i=x;i<n;i++)
    {
        if(Chart[i][y] == '*') return 0;
        if(Chart[i][y] == 'X') break;
    }
    for(int i=x;i>=0;i--)
    {
        if(Chart[i][y] == '*') return 0;
        if(Chart[i][y] == 'X') break;
    }
    for(int i=y;i<n;i++)
    {
        if(Chart[x][i] == '*') return 0;
        if(Chart[x][i] == 'X') break;
    }
    for(int i=y;i>=0;i--)
    {
        if(Chart[x][i] == '*') return 0;
        if(Chart[x][i] == 'X') break;
    }
    return 1;
}
void out()
{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",Chart[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
}
void DFS(int x,int y,int sum)
{
    //out();
    if(sum>maxx) maxx = sum;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Chart[i][j] == '.'&&judge(i,j))
            {
                Chart[i][j] = '*';
                DFS(i,j,sum+1);
                Chart[i][j] = '.';
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        getchar();
        maxx = 0;
        memset(Chart,0,sizeof(Chart));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%c",&Chart[i][j]);
            }
            getchar();
        }
        DFS(0,0,0);
        cout<<maxx<<endl;
    }
    return 0;
}

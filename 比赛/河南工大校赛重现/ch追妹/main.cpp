#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f
#define N 22
using namespace std;
int vis[N],Map[N][N],n,m,a,b,dis[N];

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int x,y,sum=0;
        memset(Map,0x3f,sizeof(Map));
        cin>>n>>m>>a>>b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            if(x==b||y==b)
                sum++;
            Map[x][y]=1;
            Map[y][x]=1;
        }
        if(Map[a][b]==1||a==b)
            printf("chhappy\n");
        else
            printf("chsad\n");
    }
    return 0;
}

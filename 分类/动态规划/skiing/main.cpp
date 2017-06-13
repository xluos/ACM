#include <iostream>
#include <bits/stdc++.h>
#define N 105
using namespace std;
int R,C,h[N][N],dp[N][N],Max;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int dfs(int x,int y)
{
    int maxx=0,ans;
    if(dp[x][y])
        return dp[x][y];
    for(int i=0;i<4;i++)
    {
        int X=x+dir[i][0];
        int Y=y+dir[i][1];
        if(X<=R&&X>0&&Y<=C&&Y>0)
        {
            if(h[X][Y]<h[x][y])
                ans=dfs(X,Y)+1;
            else
                ans=dp[x][y];
            if(maxx<ans)
                maxx=ans;
        }

    }
    dp[x][y]=maxx;
    return dp[x][y];
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        memset(dp,0,sizeof(dp));
        Max=0;
        scanf("%d %d",&R,&C);
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
        {
            scanf("%d",&h[i][j]);
        }
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
        {
            int ans=dfs(i,j);
            if(Max<ans)
                Max=ans;
        }
        cout<<Max+1<<endl;
    }
    return 0;
}

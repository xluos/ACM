#include <bits/stdc++.h>

using namespace std;
const int MAX = 205;
const int INF = 0x2a2a2a2a;
struct node
{
    int x,y,r;
};
int n;
int Chara[MAX][MAX],vis[MAX],diss[3][MAX];
node coordinate[MAX];
int judge(int i,int j)
{
    if(i == j) return 0;
    double X2 = (coordinate[i].x - coordinate[j].x)*(coordinate[i].x - coordinate[j].x);
    double Y2 = (coordinate[i].y - coordinate[j].y)*(coordinate[i].y - coordinate[j].y);
    if(sqrt(X2 + Y2) <= coordinate[i].r +coordinate[j].r)
        return 1;
    return INF;
}
void Dijkstra(int sre,int dis[])
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=0; i<n; i++)
    {
        int k,minn = INF;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        if(minn == INF) break;
        vis[k] = 1;
        for(int j=0; j<n; j++)
        {
            if(!vis[j] && dis[j] > dis[k] + Chara[k][j])
            {
                dis[j] = dis[k] + Chara[k][j];
            }
        }
    }
}
int main()
{
    int w;
    scanf("%d",&w);
    while(w--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&coordinate[i].x,&coordinate[i].y,&coordinate[i].r);
        }
        //½¨Í¼
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int ans = judge(i,j);
                Chara[i][j] = ans;
                Chara[j][i] = ans;
            }
        }
        Dijkstra(0,diss[0]);
        Dijkstra(1,diss[1]);
        Dijkstra(2,diss[2]);
        int minn = INF;
        for(int i=0; i<n; i++)
        {
            int sum = diss[0][i] + diss[1][i] + diss[2][i];
            //cout<<"sum == "<<sum<<endl;
            if(minn > sum)
            {
                minn = sum;
            }
        }
        if(minn >= INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",n - minn - 1);
        }
    }
    return 0;
}

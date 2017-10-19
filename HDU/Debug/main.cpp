#include <bits/stdc++.h>

using namespace std;
const int N = 1004;
int n,m;
double Chara[N][N],dis[N];
int vis[N];
double C[N][N];
void Dijkstra(int src)
{
    for(int i=0;i<n;i++)
    {
        dis[i] = Chara[src][i];
        vis[i] = 0;
    }
    vis[src] = 1;
    for(int j=0;j<n;j++)
    {
        double ans = 0;
        int k;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&dis[i]>ans)
            {
                ans = dis[i];
                k = i;
            }
        }
        vis[k] = 1;
        if(ans == 0) break;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&dis[i] < dis[k]*Chara[k][i])
                dis[i] = dis[k]*Chara[k][i];
        }
    }
}

int main()
{

    while(~scanf("%d",&n))
    {
        memset(C,0x3f,sizeof(C));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                double ans;
                scanf("%lf",&ans);
                if(C[i][j] < ans)
                    C[i][j] = ans;
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    Chara[i][j] = C[i][j];
                }
            }
            int a,b;
            scanf("%d %d",&a,&b);
            Dijkstra(a-1);
            if(fabs(dis[b-1])<0.00001)
                printf("What a pity!\n");
            else
                printf("%.3lf\n",dis[b-1]);
        }


    }
    return 0;
}

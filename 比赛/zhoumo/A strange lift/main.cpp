    #include <bits/stdc++.h>

    using namespace std;

    const int INF=0x3f3f3f3f;
    const int N=410;

    int n,a,b;
    int Chara[N][N],dis[N],vis[N];

    void Dijkstra(int src)
    {
        for(int i=1; i<=n; i++)
        {
            dis[i] = Chara[src][i];
            vis[i] = 0;
            //cout<<"dis"<<dis[i]<<endl;
        }
        dis[src] = 0;
        vis[src] = 1;
        for(int i=1; i<=n; i++)
        {
            int ans = INF,k;
            for(int j=1; j<=n; j++)
            {
                if(!vis[j] && dis[j] < ans)
                {
                    k = j;
                    ans = dis[j];
                }
            }
            vis[k] = 1;
            if(ans == INF) break;
            for(int j =1; j<=n; j++)
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

        while(scanf("%d",&n),n)
        {
            memset(Chara,0x3f,sizeof(Chara));
            scanf("%d %d",&a,&b);
            for(int i=1;i<=n;i++)
            {
                int ans;
                scanf("%d",&ans);
                if(i-ans > 0)
                    Chara[i][i-ans] = 1;
                if(i+ans <= n)
                    Chara[i][i+ans] = 1;
            }
            Dijkstra(a);
//            cout<<a<<' '<<b<<endl;
//            for(int i = 0;i<=n;i++)
//                printf("dis%d:%d\n",i+1,dis[i]);
            printf("%d\n",dis[b]==INF?-1:dis[b]);
//            while(1)
//            {
//                scanf("%d %d",&a,&b);
//                cout<<Chara[a][b]<<endl;
//            }
        }
        return 0;
    }

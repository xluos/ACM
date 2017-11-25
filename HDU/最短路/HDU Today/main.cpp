#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 155;
int Chara[MAX][MAX],vis[MAX],dis[MAX];
int n;
map<string,int>mp;
void Dijkstra(int sre,int sum)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i < sum;i++)
    {
        dis[i] = Chara[sre][i];
    }
    dis[sre] = 0;
    vis[sre] = 1;
    for(int i=1;i<sum;i++)
    {
        int k,minn = INF;
        for(int j=1;j<sum;j++)
        {
            if(!vis[j] && dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        if(minn == INF) break;
        vis[k] = 1;
        for(int j=1;j < sum;j++)
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
    while(scanf("%d",&n),~n)
    {
        memset(Chara,0x3f,sizeof(Chara));
        int t=1,w;
        string place1,place2,S,T;
        cin>>S>>T;
        mp[S] = t++;
        mp[T] = t++;
        for(int i=0;i<n;i++)
        {
            cin>>place1>>place2>>w;
            if(!mp[place1]) mp[place1] = t++;
            if(!mp[place2]) mp[place2] = t++;
            if(Chara[mp[place1]][mp[place2]] > w)
            {
                Chara[mp[place1]][mp[place2]] = w;
                Chara[mp[place2]][mp[place1]] = w;
            }
        }
        Dijkstra(mp[S],t);
        printf("%d\n",dis[mp[T]]==INF?-1:dis[mp[T]]);
        mp.clear();
    }
    return 0;
}
/**
测试数据 起点终点相同
6
xiasha xiasha
xiasha station 60
xiasha ShoppingCenterofHangZhou 30
station westlake 20
ShoppingCenterofHangZhou supermarket 10
xiasha supermarket 50
supermarket westlake 10

*/

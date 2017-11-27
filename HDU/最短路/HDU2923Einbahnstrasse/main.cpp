#include <bits/stdc++.h>

using namespace std;
int N,C,R;
const int MAX = 105;
const int INF = 0x3f3f3f3f;

int Chara[MAX][MAX],vis[MAX],dis[MAX];
map<string,int>mp;

void Floyd()
{
    for(int i=1;i<=N;i++)
    {
        Chara[i][i] = 0;
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j = 1;j<=N;j++)
            {
                if(Chara[i][j] > Chara[i][k] + Chara[k][j])
                {
                    Chara[i][j] = Chara[i][k] + Chara[k][j];
                }
            }
        }
    }
//    for(int i=1;i<=N;i++)
//        {
//            for(int j = 1;j<=N;j++)
//            {
//                if(Chara[i][j] < INF)
//                {
//                    printf("%d --> %d  %d\n",i,j,Chara[i][j]);
//                }
//            }
//        }
}
int main()
{
    int k = 1;
    string s,t[1005],u,v;
    char left,right;
    int w;
    while(scanf("%d %d %d",&N,&C,&R),N+C+R)
    {
        memset(Chara,INF,sizeof(Chara));
        mp.clear();
        int COUNT = 1,sum = 0 ;
        cin>>s;
        mp[s] = COUNT++;
        for(int i=0;i<C;i++)
        {
            cin>>t[i];
            if(!mp[t[i]])
            {
                mp[t[i]] = COUNT++;
            }
        }
        for(int i=0;i<R;i++)
        {
            cin>>u;
            scanf(" %c-%d-%c ",&left,&w,&right);
            cin>>v;
            //cout<<u<<w<<v<<' '<<get_direction(w)<<' '<<get_weight(w)<<endl;
            if(!mp[u]) mp[u] = COUNT++;
            if(!mp[v]) mp[v] = COUNT++;
            if(left == '<' && w < Chara[mp[v]][mp[u]])
            {
                Chara[mp[v]][mp[u]] = w;
            }
            if(right == '>' && w < Chara[mp[u]][mp[v]])
            {
                Chara[mp[u]][mp[v]] = w;
            }
        }
        Floyd();
        for(int i=0;i<C;i++)
        {
            sum += Chara[mp[s]][mp[t[i]]] + Chara[mp[t[i]]][mp[s]];
            //cout<<i<<'.'<<dis[mp[t[i]]]<<' ' + t[i]<<endl;
        }
        printf("%d. %d\n",k++,sum);
    }
    return 0;
}

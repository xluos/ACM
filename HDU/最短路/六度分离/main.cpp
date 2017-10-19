#include <bits/stdc++.h>

using namespace std;
const int N = 106;
const int MAX = 0x3f3f3f3f;

int Chara[N][N];
int n,m;
void F()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(Chara[i][k] == MAX || Chara[k][j] == MAX) continue;
                if(Chara[i][j] > Chara[i][k] + Chara[k][j])
                    Chara[i][j] = Chara[i][k] + Chara[k][j];
            }
        }
    }
}
bool judge()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Chara[i][j] > 7)
            {
                cout<<Chara[i][j]<<endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        memset(Chara,0x3f,sizeof(Chara));
        int u,v;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            Chara[u][v] = Chara[v][u] = 1;
            Chara[i][i] = 0;
        }
        F();
        if(judge())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
const int MAX = 33;
int n,m;
double Chara[MAX][MAX];
map<string,int>mp;
bool Floyd()
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(Chara[i][k]*Chara[k][j] > Chara[i][j])
                {
                    Chara[i][j] = Chara[i][k]*Chara[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(Chara[i][i] > 1)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int count = 1;
    while(~scanf("%d",&n),n)
    {
        double w;
        string str1,str2;
        memset(Chara,0,sizeof(Chara));
        for(int i=0;i<n;i++)
        {
            cin>>str1;
            mp[str1] = i;
            Chara[i][i] = 1;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            cin>>str1>>w>>str2;
            Chara[mp[str1]][mp[str2]] = w;
        }
        printf("Case %d: %s\n",count++,Floyd()?"Yes":"No");
    }
    return 0;
}

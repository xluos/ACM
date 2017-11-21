#include <bits/stdc++.h>

using namespace std;
const int MAX=1005;
int Chara[MAX][MAX];
int main()
{
    int n;
    scanf("%d",&n);
    for(int t=0;t<n;t++)
    {
        int r,c;
        memset(Chara,0,sizeof(Chara));
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&Chara[i][j]);
            }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                Chara[i][j] += max(Chara[i][j-1],Chara[i-1][j]);
            }
        }
        printf("Scenario #%d:\n",t+1);
        printf("%d\n\n",Chara[r][c]);
    }
    return 0;
}

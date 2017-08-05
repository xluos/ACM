#include <bits/stdc++.h>

using namespace std;
string mn[11];
int judge(int x,int y)
{
    int k=0;
    if(mn[x][y]!='*'&&(y==0||mn[x][y-1]=='*')) k++;
    if(mn[x][y]!='*'&&(x==0||mn[x-1][y]=='*')) k+=2;
    return k;
}
int main()
{
    int n,m,count=1;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=0;i<n;i++) cin>>mn[i];
        printf("puzzle #%d:\n",count++);
        int num=0;
        printf("Across\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int k=judge(i,j),t;
                if(k)num++;
                if(k==1||k==3)
                {
                    for(t=j+1;t<m&&mn[i][t]!='*';t++);
                    printf("%3d.",num);
                    cout<<mn[i].substr(j,t-j)<<endl;
                }
            }
        }
        num=0;
        printf("Down\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int k=judge(i,j),t;
                if(k)num++;
                if(k==2||k==3)
                {
                    printf("%3d.",num);
                    for(t=i;t<n&&mn[t][j]!='*';t++)cout<<mn[t][j];
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}

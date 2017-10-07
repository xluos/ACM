#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dir[][2]= {0,1,0,-1,1,0,-1,0};
int main()
{
    int m,n,k;
    int a[105][105]= {0};
    scanf("%d %d %d ",&n,&m,&k);
    for(int i=0; i<=n; i++)
        a[i][0]=1;
    for(int i=0; i<=m; i++)
        a[0][i]=1;
    for(int i=0; i<k; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x)
        {
            for(int j=0; j<=n; j++)
                a[j][y]=1;
        }
        else
        {
            for(int j=0; j<=m; j++)
                a[y][j]=1;
        }

    }
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(!a[i][j])
            {a[i][j]=1;
            for(int k=0; k<4; k++)
            {
                if(a[i+dir[k][0]][j+dir[k][1]]==0&&(i+dir[k][0])<=n&&(j+dir[k][1])<=m)
                {
                    a[i+dir[k][0]][j+dir[k][1]]=1;
                    sum++;
                    break;
                }
            }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}

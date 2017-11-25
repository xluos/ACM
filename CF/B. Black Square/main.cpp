#include <bits/stdc++.h>

using namespace std;
int n,m,flag=1,b,w;
char mp[105][105];
int bian()
{
    int maxx=0,minx=INFINITY,miny=INFINITY,maxy=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='B')
            {
                if(maxx<i)maxx=i;
                if(minx>i)minx=i;
                if(maxy<j)maxy=j;
                if(miny>j)miny=j;
            }
        }
    }
    int l=maxx-minx+1,h=maxy-miny+1;
    if(max(l,h)<=min(n,m))
    {
        return max(l,h)*max(l,h)-b;
    }
    else
    {
        return -1;
    }
}
int main()
{
    cin>>n>>m;getchar();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%c",&mp[i][j]);
            if(mp[i][j]=='B')
            {
                if(flag)flag=0;
                b++;
            }
            else
            {
                w++;
            }
        }
        getchar();
    }
    if(flag)printf("1\n");
    else
    {
        printf("%d\n",bian());
    }
    return 0;
}

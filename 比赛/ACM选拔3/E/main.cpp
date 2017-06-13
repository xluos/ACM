#include <cstdio>
#include <iostream>
#include <cstring>
#define N 1004
using namespace std;
int a[N][N];

int main()
{
    int n,m,bushu=0,sum,x=0,y=0;
    scanf("%d%d",&m,&n);
    sum=n*m;
    memset(a,-1,sizeof(a));
    a[0][0]=0;
    while(bushu<sum-1)
    {
        while(x+1<n&&a[y][x+1]==-1) a[y][++x]=++bushu%26;
        while(y+1<m&&a[y+1][x]==-1) a[++y][x]=++bushu%26;
        while(x-1>=0&&a[y][x-1]==-1) a[y][--x]=++bushu%26;
        while(y-1>=0&&a[y-1][x]==-1) a[--y][x]=++bushu%26;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
    {
        printf("   %c",a[i][j]+'A');
    }
    printf("\n");
    }
    return 0;
}







/*#include <iostream>
#include <string.h>

using namespace std;
int mymap[1000][1000];
int flag=0;
int x,y;
int su;
int M,N;
void yi()
{
    for(;x<N;x++)
    {
        if(mymap[y][x]!=0)
        {
            x--;
            flag=1;
            break;

        }
        else
        {
          mymap[y][x]=su;
          su++;
          if(su>26)
            su=1;

        }

    }

}
void er()
{

    for(;y<M;y++)
    {
        if(mymap[y][x]!=0)
        {
            if(mymap[y+1][x]!=0)
            {
                flag=1;
            }
            break;

        }
        mymap[y][x]=su;
        su++;
        if(su>26)
            su=1;
    }
}
void san()
{
    for(;x>=0;x--)
    {
        if(mymap[y][x]!=0)
        {
            if(mymap[y-1][x]!=0)
            {
                flag=1;
            }
            break;
        }
        mymap[y][x]=su;
        su++;
        if(su>26)
            su=1;
    }
}
void si()
{

    for(;y>=0;y--)
    {
        if(mymap[y][x]!=0)
        {
            if(mymap[y][x+1]!=0)
            {
                flag=1;
            }
            break;
        }
        mymap[y][x]=su;
        su++;
        if(su>26)
            su=1;
    }
}
int main()
{

    cin>>M>>N;
    x=0;
    y=0;
    memset(mymap,0,sizeof(mymap));
    su=1;
    while(1)
    {
        yi();
        if(flag==1)
            break;
        er();
        if(flag==1)
            break;
        san();
        if(flag==1)
            break;
        si();
        if(flag==1)
            break;
    }
    for(int i=0;i<20;i++)
    {
         for(int j=0;j<20;j++)
            cout<<mymap[i][j];
         cout<<endl;
    }

    return 0;
}*/

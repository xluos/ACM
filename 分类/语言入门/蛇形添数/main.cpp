#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[105][105];
void init(int x)
{
    memset(a,0,sizeof(a));
    int i,j;x++;
    for(i=j=0;j<=x;j++)
        a[i][j]=-1;
    for(i=j=0;i<x;i++)
        a[i][j]=-1;
    for(i=j=x;j>=0;j--)
        a[i][j]=-1;
    for(i=j=x;i>0;i--)
        a[i][j]=-1;
}
int main()
{
    int n,sum,count=1;
    cin>>n;sum=n*n;
    init(n);
    int i=1,j=n;
    while(1)
    {
        if(count==sum)break;
        for(;a[i+1][j]==0;i++)a[i][j]=count++;
        for(;a[i][j-1]==0;j--)a[i][j]=count++;
        for(;a[i-1][j]==0;i--)a[i][j]=count++;
        for(;a[i][j+1]==0;j++)a[i][j]=count++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0)a[i][j]=sum;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

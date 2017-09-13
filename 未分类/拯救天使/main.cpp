#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct mg{
    int data,x,y,num;
};
mg a[200][200]
int vis[200][200];
int main()
{
    int n,m;
    int ai,aj,ri,rj;
    queue<mg> q;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]=='a')
            {ai=i;aj=j;}
            if(a[i][j]=='r')
            {ri=i;rj=j;}
        }
        q.push(a[ai][aj]);
        while(!q.empty())
        {
            q.front()
        }
    }
    return 0;
}

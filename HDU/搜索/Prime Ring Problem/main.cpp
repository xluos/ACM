#include <bits/stdc++.h>

using namespace std;
int Prime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,
             0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,
             0,1,0,0,0,0,0,0};
int vis[40],num[22];
void DFS(int k,int N)
{
    if(k == N - 1 && Prime[num[k]+1])
    {
        printf("%d",num[0]);
        for(int i=1;i<N;i++)
        {
            printf(" %d",num[i]);
        }
        printf("\n");
    }
    for(int i=2;i<=N;i++)
    {
        if(!vis[i]&&Prime[num[k]+i])
        {
            //cout<<i<<' '<<num[k]<<endl;
            vis[i] = 1;
            num[k+1] = i;
            DFS(k+1,N);
            vis[i] = 0;
        }
    }
}
int main()
{
    int n,t=1;;
    while(~scanf("%d",&n))
    {
        int k=0;
        memset(vis,0,sizeof(vis));
        memset(num,0,sizeof(num));
        num[0]=1;
        printf("Case %d:\n",t++);
        DFS(0,n);
        printf("\n");
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
int num[1005],target[1005];
int n,m,k=1,flag=0;
int dfs(int i,int sum)
{
    if(sum == n)
    {
        for(int j=0;j<k-1;j++)
            printf("%d+",target[j]);
        printf("%d\n",target[k-1]);
        flag = 1;
    }
    if(sum < n)
    for(int j=i;j<m;j++)
    {
        if(j>i&&num[j]==num[j-1]) continue;
        sum+=num[j];
        target[k++] = num[j];
        dfs(j+1,sum);
        sum-=num[j];
        k--;
    }
}
int main()
{

    while(~scanf("%d %d",&n,&m),n+m)
    {
        flag = 0;
        k = 0;
        memset(num,0,sizeof(num));
        memset(target,0,sizeof(num));
        for(int i = 0;i < m; i++)
        {
            scanf("%d",&num[i]);
        }
        printf("Sums of %d:\n",n);
        dfs(0,0);
        if(!flag) printf("NONE\n");
    }
    return 0;
}

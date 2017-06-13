#include <iostream>
#include <bits/stdc++.h>
#define N 1005
#define M 105
using namespace std;
int f[N][N],c[M],w[M],n,v,k,dp[M],dp2[M];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        memset(f,0,sizeof(f));
        scanf("%d %d %d",&n,&v,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        for(int i=0;i<n;i++)
            for(int j=v;j>=c[i];j--)
        {
            for(int t=1;t<=k;t++)
            {
                dp[t]=f[j][t];
                dp2[t]=f[j-c[i]][t] + w[i];
            }
            dp[k+1]=-1;
            dp2[k+1]=-1;
            for(int t=1,a=1,b=1;t<=k&&(dp[a]!=-1||dp2[b]!=-1);t++)
            {
                if(dp[a]>dp2[b])
                {
                    f[j][t]=dp[a];
                    a++;
                }
                else
                {
                    f[j][t]=dp2[b];
                    b++;
                }
                if(f[j][t]==f[j][t-1])
                    t--;
            }

        }
        cout<<f[v][k]<<endl;

    }
    return 0;
}
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <queue>
//#include <algorithm>
//using namespace std;
//typedef long long LL;
//const int MAX =  1100;
//int Dp[MAX][35];
//int w[110],V[110];
//int A[35];
//int B[35];
//int main()
//{
//    int T;
//    int n,v,k;
//    scanf("%d",&T);
//    while(T--)
//    {
//        scanf("%d %d %d",&n,&v,&k);
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&w[i]);
//        }
//        for(int i=1;i<=n;i++)
//        {
//            scanf("%d",&V[i]);
//        }
//        memset(Dp,0,sizeof(Dp));
//        for(int i=1;i<=n;i++)//转化为01背包减少时间复杂度
//        {
//            for(int j=v;j>=V[i];j--)
//            {
//                int s;
//                for( s=1;s<=k;s++)
//                {
//                    A[s]=Dp[j-V[i]][s]+w[i];
//                    B[s]=Dp[j][s];
//                }
//                A[s]=-1;
//                B[s]=-1;
//                int a=1,b=1;
//                for(s=1;s<=k&&(A[a]!=-1||B[b]!=-1);)//采用归并的方式,也可以用优先队列
//                {
//                    if(A[a]>B[b])
//                    {
//                        Dp[j][s]=A[a];
//                        a++;
//                    }
//                    else
//                    {
//                        Dp[j][s]=B[b];
//                        b++;
//                    }
//                    if(Dp[j][s]!=Dp[j][s-1])
//                    {
//                        s++;
//                    }
//                }
//            }
//        }
//        printf("%d\n",Dp[v][k]);
//    }
//    return 0;
//}

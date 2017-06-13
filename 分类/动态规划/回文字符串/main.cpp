#include <bits/stdc++.h>
#define N 1005
using namespace std;
char s[N],s2[N];
int LCS(int l,int l2)
{
    int dp[3][N];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<l2; j++)
        {
            if(s[i]==s2[j])
            {
                dp[i%2+1][j]=dp[(i+1)%2+1][j-1]+1;
            }
            else
            {
                dp[i%2+1][j]=max(dp[(i+1)%2+1][j],dp[(i)%2+1][j-1]);
            }
        }
    }
    return dp[(l-1)%2+1][l2-1];
}
int main()
{
    int w,l;
    cin>>w;
    getchar();
    while(w--)
    {
        gets(s);
        l=strlen(s);
        reverse_copy(s,s+l,s2);
        s2[l]=0;
        printf("%d\n",l-LCS(l,l));
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int dp[3][10005];
    char s[1005],s2[1005];
    int w;cin>>w;
    getchar();
    while(w--)
    {
        memset(dp,0,sizeof(dp));
        gets(s);gets(s2);
        int l=strlen(s),l2=strlen(s2);
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l2;j++)
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
        cout<<dp[(l-1)%2+1][l2-1]<<endl;

    }
    return 0;
}

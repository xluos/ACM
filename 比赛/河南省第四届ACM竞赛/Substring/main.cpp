#include <bits/stdc++.h>

using namespace std;
//int main()
//{
//    int w;
//    char s[100],s2[100];
//    cin>>w;getchar();
//    while(w--)
//    {
//        int ma=-1,flag=0;
//        int dp[100][100];
//        gets(s);
//        int len=strlen(s);
//        reverse_copy(s,s+len,s2);
//        for(int i=0;i<len;i++)
//        {
//            for(int j=0;j<len;j++)
//            {
//                if(s[i]==s2[j])
//                {
//                    dp[i][j]=dp[i-1][j-1]+1;
//                }
//                else
//                    dp[i][j]=0;
//                if(ma<dp[i][j])
//                {
//                    ma=dp[i][j];
//                    flag=i;
//                }
//
//            }
//        }
//        for(int i=flag-ma+1;i<=flag;i++)
//        {
//            printf("%c",s[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//int const MAX = 100;
//char s[MAX << 1];
//int p[MAX << 1];
//int flag;
//int Manacher(char s[])
//{
//	int len = strlen(s);
//	for(int i = len; i >= 0; i--)
//	{
//		s[(i << 1) + 2] = s[i];
//		s[(i << 1) + 1] = '#';
//	}
//	s[0] = '*';
//	int cur = 0, ans = 0 ;
//	for(int i = 2; i < 2 * len + 1; i++)
//	{
//		if(p[cur] + cur >= i)
//			p[i] = min(p[(cur << 1) - i], p[cur] + cur - i);
//		else
//			p[i] = 1;
//		while(s[i - p[i]] == s[i + p[i]])
//			p[i] ++;
//		if(p[cur] + cur < i + p[i])
//			cur = i;
//		//ans = max(ans, p[i]);
//        if(ans < p[i])
//        {
//            ans=p[i];
//            flag=i;
//        }
//	}
//	return ans-1;
//}
//int main()
//{
//    int w;
//    cin>>w;getchar();
//    while(w--)
//    {
//        char s[110],s2[100];
//        gets(s);
//        strcpy(s2,s);
//        int l=Manacher(s);
//        int f=flag/2-l/2-1;
//        for(int i=f;i<f+l;i++)
//        {
//            printf("%c",s2[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}
#define N 1005
int flag=0,ma=-1;
char s[N],s2[N];
int LCS(int l,int l2)
{
    int dp[3][N];
    ma=-1;flag=0;
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
                dp[i%2+1][j]=0;
            }
            if(ma<dp[i%2+1][j])
            {
                ma=dp[i%2+1][j];
                flag=i;
            }
        }
    }
    return ma;
}

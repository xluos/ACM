#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int judge(int n)//wa了n次最后发现判断素数的写错了真是太长时间没有刷题手生啊
{
    int i=0;
    if(n==1||n==0)return 0;
    for(i=2;i<=sqrt(n);i++)
        if(!(n%i))return 0;
    return 1;
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        char s[110];
        int sum[26]={0},i;
        cin>>s;
        for(i=0;s[i];i++)
            sum[s[i]-'a']++;
        sort(sum,sum+26);
        for(i=0;sum[i]==0;i++);
        if(i==25)i=0;
        if(judge(sum[25]-sum[i]))
            printf("Lucky Word\n%d\n",sum[25]-sum[i]);
        else
            printf("No Answer\n0\n");
    }
    return 0;
}

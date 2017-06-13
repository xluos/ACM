#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ss[5000];
int shu[500];
void sushu()
{
    int t=1;
    ss[0]=ss[1]=1;
    for(int i=2;i<2500;i++)
    {
        if(!ss[i])
        {
            shu[t]=i;t++;
            for(int j=i+i;j<5000;j+=i)
                ss[j]=1;
        }

    }
}
int main()
{
    sushu();
    char s[100];
    while(~scanf("%s",s))
    {
        int l=strlen(s),sum=0;
        for(int i=l-1;i>=0;i--)
        {
            if(s[i]=='1')
                sum+=shu[l-i];
        }
        printf("%d\n",sum);
    }
    return 0;
}

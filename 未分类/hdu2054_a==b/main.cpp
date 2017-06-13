#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int chuli(char s[])
{
    int k=0,t,i,len=strlen(s),flag=0;
    for(int i=0; i<len; i++)
        if(s[i]=='.')
        {flag=1;t=i;break;}
    if(flag)
    {
        for(i=len-1;i>=t&&s[i]=='0'||s[i]=='.'; i--);
        s[i+1]=0;
        len=i+1;
    }
    for(k=0; s[k]=='0'; k++);
    return k;
}
int main()
{
    char s[100001],s2[100001];
    int k,k2;
    while(~scanf("%s %s",s,s2))
    {
        k=chuli(s);
        k2=chuli(s2);
        printf("%s %s\n",s+k,s2+k2);
        if(strcmp(s+k,s2+k2)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

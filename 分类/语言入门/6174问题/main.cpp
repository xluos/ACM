#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
void itoa(int a,char *s,bool t)
{
    int i,j;
    for(i=0;a;i++)
    {
        s[i]=a%10+'0';
        a/=10;
    }
    s[i]='\0';
    int l=strlen(s);
    if(t)sort(s,s+l,cmp);
    else sort(s,s+l);
}
int atoi(char *s)
{
    int sum=0;
    for(int i=0;s[i];i++)
        sum=sum*10+s[i]-'0';
    return sum;
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        int a;
        cin>>a;
        int ans,i;
        for(i=1;;i++)
        {
            char s[5],s2[5];
            itoa(a,s,true);
            itoa(a,s2,false);
            ans=a;
            a=atoi(s)-atoi(s2);
            if(a==ans)break;
        }
        cout<<i<<endl;
    }
    return 0;
}

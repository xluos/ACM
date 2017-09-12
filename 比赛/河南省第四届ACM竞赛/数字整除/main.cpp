#include <bits/stdc++.h>
#define N 105
using namespace std;
int jian(char s[],char s2[])
{
    int a[N]={0},a2[10]={0};
    int t=0;
    int len=strlen(s);
    int len2=strlen(s2);
    for(int i=0;i<len;i++)
    {
        a[i]=s[len-1-i]-'0';
        //cout<<a[i];
    }
    //cout<<endl;
    for(int i=0;i<len2;i++)
    {
        a2[i]=s2[len2-1-i]-'0';
        //cout<<a2[i];
    }
    //cout<<endl;
    for(int i=0;i<N;i++)
    {
        a[i]=a[i]-a2[i];
        //cout<<a[i];
        if(a[i]<0)
        {
            a[i+1]--;
            a[i]+=10;
        }
        if(a[i+1]>0&&i>len2)break;
    }
    for(int i=N-1;i>=0;i--)
    {
        if(a[i]==0)continue;
        //cout<<a[i]<<' '<<i<<endl;
        s[t++]=a[i]+'0';
    }
    s[t]=0;
    return t;
}
int _17(char s[],int n)
{
    int l=strlen(s);
    if(l<10)
    {
        int ans;
        sscanf(s,"%d",&ans);
        return (ans-5*n)%17;
    }
    //cout<<'a'<<endl;
    if(n==0)
    {
        int ans=(s[l-1]-'0');
        //cout<<ans<<endl;
        s[l-1]=0;
        return _17(s,ans);
    }
    char s2[10];
    sprintf(s2,"%d",n*5);
    l=jian(s,s2);
    int ans=(s[l-1]-'0');
    s[l-1]=0;
    //cout<<l<<endl;
    return _17(s,ans);
    //cout<<'a'<<endl;
}
int main()
{
    char s[N];
    while(gets(s),s[0]!='0')
    {
        if(_17(s,0))
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}

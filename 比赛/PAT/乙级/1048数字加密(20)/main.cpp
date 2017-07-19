#include <bits/stdc++.h>

using namespace std;
char ji(char a,char b)
{
    int ans=a+b-'0'*2;
    if(ans%13<10)return ans%13+'0';
    else if(ans==10) return 'J';
    else if(ans==11) return 'Q';
    else if(ans==12) return 'K';
}
char ou(char a,char b)
{
    if(b-a>=0) return b-a+'0';
    else return b-a+10+'0';
}
int main()
{
    char a[105],b[105],l,l2,ll;
    scanf("%s %s",a,b);
    l=strlen(a);l2=strlen(b);
    reverse(a,a+l);reverse(b,b+l2);
    if(l<l2)
    {
        ll=l2;
        for(;l<l2;l++)
            a[l]='0';
        a[l]=0;
    }
    else
    {
        ll=l;
        for(;l2<l;l2++)
            b[l2]='0';
        b[l2]=0;
    }
    for(int i=0;i<ll;i++)
    {
        if(i%2)
            b[i]=ou(a[i],b[i]);
        else
            b[i]=ji(a[i],b[i]);
    }
    reverse(b,b+ll);
    l=0;
    while(b[l]=='0')l++;
    if(strlen(b)==l)
        printf("0\n");
    else
        printf("%s\n",b+l);
    return 0;
}

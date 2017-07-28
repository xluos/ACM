#include <bits/stdc++.h>

using namespace std;
int judeg(char s[])
{
    int l=strlen(s),flag=0,k=l;
    int i=s[0]=='-'?1:0;
    for(;i<l;i++)
    {
        if((s[i]>='0'&&s[i]<='9')||s[i]=='.')
            {if(s[i]=='.'){flag++;k=i;}}
        else return 0;
    }
    if(flag>1||l-k>3)return 0;
    return 1;
}
double AVG(char s[])
{
    if(!judeg(s)) return 9999;
    double n;
    sscanf(s,"%lf",&n);
    return n;
}
int main()
{
    int n,m=0;
    double avg,sum=0;
    char s[105];
    cin>>n;
    while(n--)
    {
        scanf("%s",s);
        avg=AVG(s);
        if(avg<-1000||avg>1000)
            printf("ERROR: %s is not a legal number\n",s);
        else
        {
           m++; sum+=avg;
        }
    }
    printf("The average of %d number%c is ",m,m==1?' ':'s');
    if(m) printf("%.2lf\n",sum/m);
    else printf("Undefined\n");
    return 0;
}

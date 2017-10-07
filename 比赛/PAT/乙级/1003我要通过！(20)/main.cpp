#include <bits/stdc++.h>

using namespace std;
int judge_1(char s[])
{
    int l=strlen(s),p=1,t=1;
    for(int i=0;i<l;i++)
    {
        if(!(s[i]=='P'||s[i]=='A'||s[i]=='T'))
            return 0;
        if(s[i]=='P')
        {
            if(p) p=0;
            else return 0;
        }
        if(s[i]=='T')
        {
            if(t) t=0;
            else return 0;
        }
    }
    return 1;
}
int judge_2(char s[])
{
    int l=strlen(s),p,t;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='P') p=i;
        if(s[i]=='T') t=i;
    }
    if(t-p>1&&p*(t-p-1)==l-t-1)
    {
        return 1;
    }
    else return 0;
}
int judge(char s[])
{
    return (judge_1(s)&&judge_2(s));
}
int main()
{
    int n;
    char s[105];
    cin>>n;
    while(n--)
    {
        scanf("%s",s);
        if(judge(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

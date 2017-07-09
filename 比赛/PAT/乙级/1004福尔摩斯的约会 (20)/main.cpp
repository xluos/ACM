#include <bits/stdc++.h>

using namespace std;
string DAY[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    char s[200],s2[100];
    scanf("%s",s);
    int l=strlen(s),l2,flag=0,hh,mm,day;
    scanf("%s",s2);
    l2=strlen(s2);
    for(int i=0;i<l2;i++)
    {
        if(s2[i]==s[i])
        {
            if(!flag&&s2[i]>='A'&&s2[i]<='G')
            {
                flag=1;
                day=s2[i]-'A';
            }
            else if(flag&&(s2[i]>='A'&&s2[i]<='N'||s2[i]>='0'&&s2[i]<='9'))
            {
                if(s[i]>='0'&&s[i]<='9')
                    hh = s2[i]-'0';
                else
                    hh = s2[i]-'A'+10;
                break;
            }
        }
    }
    scanf("%s",s);
    l=strlen(s);
    scanf("%s",s2);
    l2=strlen(s2);
    for(int i=0;i<l2;i++)
    {
        if(s2[i]==s[i]&&(s2[i]>='A'&&s2[i]<='Z'||s2[i]>='a'&&s2[i]<='z'))
        {
            mm=i;
            break;
        }
    }
    cout<<DAY[day];
    printf(" %02d:%02d\n",hh,mm);
    return 0;
}
/**
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
*/

#include <bits/stdc++.h>

using namespace std;
string DAY[7]={"MON","TUE","TUE","THU","FRI","SAT","SUN"};
int main()
{
    char s[200];
    scanf("%s",s);
    int l=strlen(s),flag=0,hh,mm,day;
    scanf("%s",s+l);
    l=strlen(s);
    map<char, int>mp;
    for(int i=0;i<l;i++)
    {
        if(mp[s[i]])
        {
            if(!flag)
            {
                day=s[i]-'A';
                flag++;
            }
            else
            {
                if(s[i]>='0'&&s[i]<='9')
                    hh=s[i]-'0';
                else
                    hh=s[i]-'A'+10;
            }
            if(flag==2)
                break;
        }
        else
        {
            mp[s[i]]=1;
        }
    }
    scanf("%s",s);
    l=strlen(s);
    scanf("%s",s+l);
    l=strlen(s);
    mp.clear();
    for(int i=0;i<l;i++)
    {
        if(mp[s[i]])
        {
            mm=i;
            break;
        }
    }
    cout<<DAY[day];
    printf(" %02d:%02d\n",hh,mm);
    return 0;
}

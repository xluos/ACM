#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[100],s2[100];
    set<char>se;
    map<char ,int >flag;
    gets(s);gets(s2);
    int l=strlen(s2);
    for(int i=0;i<l;i++)
    {
        se.insert(s2[i]);
    }
    l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(!se.count(s[i])&&!flag[s[i]])
        {
            flag[s[i]]=1;
            if(s[i]>='a'&&s[i]<='z')
            {
                printf("%c",s[i]-32);
                flag[s[i]-32]=1;
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                flag[s[i]+32]=1;
                printf("%c",s[i]);
            }
            else
            {
                printf("%c",s[i]);
            }

        }
    }
    cout<<endl;
    return 0;
}


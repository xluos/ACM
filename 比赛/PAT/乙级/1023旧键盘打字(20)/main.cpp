#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mp[300]={0},l;
    char s[40],s2[100005];
    scanf("%s %s",s,s2);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            mp[s[i]]=1;
            mp[s[i]+32]=1;
        }
        else
            mp[s[i]]=1;
    }
    l=strlen(s2);
    for(int i=0;i<l;i++)
    {
        if(s2[i]>='A'&&s2[i]<='Z')
        {
            if(!mp['+']&&!mp[s2[i]])
                printf("%c",s2[i]);
        }
        else
        {
            if(!mp[s2[i]])
                printf("%c",s2[i]);
        }
    }
    return 0;
}
/**

7+IE.
7_This_is_a_test.
*/

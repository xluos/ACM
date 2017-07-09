#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mp[30]={0},maxx=0;
    char ch;
    while(scanf("%c",&ch),ch!='\n')
    {
        if(ch>='A'&&ch<='Z')
            ch+=32;
        if(ch>='a'&&ch<='z')
            mp[ch-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(mp[i]>mp[maxx])
            maxx=i;
    }
    printf("%c %d\n",maxx+'a',mp[maxx]);
    return 0;
}

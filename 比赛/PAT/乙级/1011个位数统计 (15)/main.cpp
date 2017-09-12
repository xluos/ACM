#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mp[10]={0};
    char ch;
    while(~scanf("%c",&ch))
    {
        mp[ch-'0']++;
    }
    for(int i=0;i<10;i++)
    {
        if(mp[i])
            printf("%d:%d\n",i,mp[i]);
    }
    return 0;
}

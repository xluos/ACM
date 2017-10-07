#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    char s[101],me[101];
    while(scanf("%d",&n),~n)
    {
        int k=0,d=0;
        scanf("%s %s",s,me);
        map<char,int>mp;
        for(i=0;i<strlen(s);i++)
        {
            if(!mp[s[i]]) k++;
            mp[s[i]]=1;;
        }
        for(i=0;i<strlen(me);i++)
        {
            if(mp[me[i]]) {k--;mp[me[i]]=0;}
            else d++;
            if(k==0||d>6) break;
        }
        printf("Round %d\n",n);
        if(d>6) printf("You lose.\n");
        else if(k) printf("You chickened out.\n");
        else printf("You win.\n");
    }

    return 0;
}

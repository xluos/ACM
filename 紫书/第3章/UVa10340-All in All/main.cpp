#include <bits/stdc++.h>

using namespace std;
#define N 1000005
char s[N],s2[N];
int main()
{
    while(~scanf("%s %s",s,s2))
    {
        int l=strlen(s),l2=strlen(s2),i,j;
        for(i=0,j=0; i<l&&j<l2; j++)
        {
            if(s[i]==s2[j])i++;
        }
        if(i==l) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

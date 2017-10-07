#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char s[1004],s2[1004];
    int w;cin>>w;
    getchar();
    while(w--)
    {
        scanf("%s %s",s,s2);
        int l=strlen(s);
        if(!strcmp(s,s2))
        {
            sort(s,s+l);
            for(int i=1;i<l;i++)
            {
                if(s[i]==s[i-1])
                    goto go;
            }
            printf("NO\n");
            continue;
        }
        sort(s,s+l);
        go :;
        sort(s2,s2+l);
        if(!strcmp(s,s2))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

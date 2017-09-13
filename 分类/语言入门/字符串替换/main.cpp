#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char s[1010];
    while(gets(s))
    {
        int l=strlen(s);
        for(int i=0;i<l-3;i++)
        {
            if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u')
            {
                s[i]='w';
                s[i+1]='e';
                s[i+2]=-1;
            }
        }
        for(int i=0;i<l;i++)
        {
            if(s[i]==-1)
                continue;
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}

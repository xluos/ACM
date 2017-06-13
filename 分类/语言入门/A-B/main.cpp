#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char c[500]={0},s[10005],s2[10005];
    gets(s);gets(s2);
    int l=strlen(s2);
    for(int i=0;i<l;i++)
        c[s2[i]]++;
    l=strlen(s);
    for(int i=0;i<l;i++)
        if(!c[s[i]])
        printf("%c",s[i]);
    printf("\n");
    return 0;
}

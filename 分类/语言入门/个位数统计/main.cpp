#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char s[1010];
    cin>>s;
    int a[10]={0},l=strlen(s);
    for(int i=0;i<l;i++)
    {
        a[s[i]-'0']++;
    }
    for(int i=0;i<10;i++)
        if(a[i])
            printf("%c:%d\n",i+'0',a[i]);
    return 0;
}

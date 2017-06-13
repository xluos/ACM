#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        char s[1100];
        int a[26]={0},max=-1,k;
        cin>>s;
        for(int i=0;s[i];i++)
            a[s[i]-'a']++;
        for(int i=0;i<26;i++)
        if(a[i]>max){max=a[i],k=i;}
        printf("%c\n",k+'a');
    }
    return 0;
}

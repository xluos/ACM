#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char a[1005][1005],s[1005];
void init(int n,int m)
{
    for(int i=0;i<n+5;i++)
        for(int j=0;j<m+5;j++)
            a[i][j]=' ';
}
int main()
{
    int w;
    scanf(" %d ",&w);
    gets(s);
    int l=strlen(s);
    int li=0.5+l/w,t=0;
    init(li,w);
    if(l>w){
    for(int i=li-1;i>=0;i--)
        for(int j=0;j<w;j++)
    {
        if(t<l)
        {
            a[j][i]=s[t++];
        }
    }
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<li;j++)
            printf("%c",a[i][j]);
        cout<<endl;
    }}
    else
    {
        for(int i=0;i<w;i++)
            if(i<l)
            cout<<s[i]<<endl;
            else
            cout<<' '<<endl;
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void itoa(int a,char *s)
{
    int i,j;
    for(i=0;a;i++)
    {
        s[i]=a%10+'0';
        a/=10;
    }
    s[i-1]='\0';
}
int atoi(char *s)
{
    int sum=0;
    int l=strlen(s);
    for(int i=l-1;i>=0;i--)
        sum=sum*10+s[i]-'0';
    return sum;
}
int main()
{
    char a[100];
    int w;cin>>w;
    while(w--)
    {
        int n;
        cin>>n;
        itoa(n,a);
        cout<<atoi(a)<<endl;
    }
    return 0;
}

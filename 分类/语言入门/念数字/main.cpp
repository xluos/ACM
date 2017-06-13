#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char s[][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};
    char ss[100];
    cin>>ss;
    int i=0,l=strlen(ss);
    if(ss[0]=='-')
    {cout<<"fu ";i=1;}
    for(;i<l;i++)
        if(i==l-1)
            cout<<s[ss[i]-'0']<<endl;
        else
            cout<<s[ss[i]-'0']<<' ';
    return 0;
}

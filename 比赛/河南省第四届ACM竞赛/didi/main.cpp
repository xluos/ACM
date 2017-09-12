#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,sum=0;
    char c[10];
    while(~scanf("%d%d=%s",&a,&b,c))
    {
        int n=0;
        int l=strlen(c);
        for(int i=0;i<l;i++)
            n=n*10+c[i]-'0';
        if(a+b==n)
            sum++;
    }
    cout<<sum<<endl;
    return 0;
}

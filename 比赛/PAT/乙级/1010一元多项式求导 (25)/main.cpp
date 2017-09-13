#include <bits/stdc++.h>

using namespace std;
int flag=0;
void fx(int a,int b)
{
    if(a*b)
    {
        if(flag) cout<<' '; flag=1;
        printf("%d %d",a*b,b-1);
    }
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        fx(a,b);
    }
    if(!flag) printf("0 0\n");
    return 0;
}

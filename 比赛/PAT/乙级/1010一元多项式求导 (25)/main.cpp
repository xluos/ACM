#include <bits/stdc++.h>

using namespace std;
int flag=0;
void fx(int a,int b)
{
    flag=1;
    if(a*b) printf("%d %d",a*b,b-1);
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(flag) cout<<' ';
        fx(a,b);
        cout<<'*';
    }
    if(!flag) printf("0 0\n");
    return 0;
}

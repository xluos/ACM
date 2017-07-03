#include <bits/stdc++.h>

using namespace std;
void out_char(int n,char ch)
{
    while(n--)printf("%c",ch);
}
int main()
{
    int n,i,sum=0;
    char ch;
    scanf("%d %c",&n,&ch);
    for(i=1;;i++)
    {
        sum+=i*2-1;
        if(sum*2-1>n)
        {i--;sum=0;break;}
    }
    for(int j=0;j<i-1;j++)
    {
        out_char(j,' ');
        out_char((i-j)*2-1,ch);
        sum+=(i-j)*2-1;
        cout<<endl;
    }
    for(int j=i-1;j>=0;j--)
    {
        out_char(j,' ');
        out_char((i-j)*2-1,ch);
        sum+=(i-j)*2-1;
        cout<<endl;
    }
    cout<<n-sum<<endl;
    return 0;
}

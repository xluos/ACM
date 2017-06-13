#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a;
int guo[5];
int zhaoguo()
{
    for(int i=1;i<=4;i++)
        if(guo[i]==0)
    {
        return i;
    }
    return 0;
}
void guo_j()
{
    for(int i=1;i<5;i++)
    {
        if(guo[i])
            guo[i]--;
    }
}
void guo_cls()
{
    for(int i=1;i<5;i++)
    {
        guo[i]=0;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,t,shijian=6,ans;
        cin>>n;
        guo_cls();ans=0;
        for(int i=0;i<n;i++)
        {
            shijian=6;
            cin>>a;
            while(!zhaoguo())
            {
                a++;
                guo_j();
                shijian=5;
            }
            if(i==n-1)
            {
                cout<<a+shijian<<endl;
                break;
            }
            guo[zhaoguo()]=shijian;
            guo_j();
        }
        if(n==0)
            cout<<0<<endl;
    }
    return 0;
}



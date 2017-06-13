#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n[5]={0},k,d;
int num[5];
int dir[]={4,1,2,3};
int judeg(int x,int y)
{
    int flag=n[k-1]+num[k]-d+1;
    int origin=n[dir[(x+y)%4]]-min(x,y)+1;
    for(int i=0;i<12;i++)
    {
        if(origin>54)
            origin-=54;
        if(origin==flag)
            {
                cout<<'('<<x<<','<<y<<')'<<endl;
                return 1;
            }
        origin+=2;
    }
    return 0;
}
int main()
{
    int x,y,sum=0;
    for(int i=1;i<5;i++)
    {
        cin>>n[i];
        num[i]=n[i];
        n[i]+=n[i-1];
    }
    cin>>k>>d;
    for(x=1;x<7;x++)
        for(y=x;y<7;y++)
            sum+=judeg(x,y);
    cout<<sum<<endl;
    return 0;
}

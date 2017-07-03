#include <bits/stdc++.h>
#define XDATE 20140906
#define JIE 2000000
using namespace std;

int main()
{
    string mins,maxs,ans;
    int minn=XDATE,maxx=0,y,m,d,data,sum=0;
    int n;cin>>n;
    while(n--)
    {
        cin>>ans;
        scanf("%d/%d/%d",&y,&m,&d);
        data=y*10000+m*100+d;
        if(data<XDATE&&XDATE-data<=JIE)
        {
            sum++;
            if(data>maxx)
            {maxx=data;maxs=ans;}
            if(data<minn)
            {minn=data;mins=ans;}
        }
    }
    cout<<sum<<' '<<mins<<' '<<maxs<<endl;
    return 0;
}

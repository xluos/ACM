#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,f,dui[1005]={0},maxd=0,maxx=0;
    cin>>n;
    while(n--)
    {
        scanf("%d-%*d %d",&d,&f);
        dui[d]+=f;
        if(dui[d]>maxx)
        {
            maxd=d;maxx=dui[d];
        }
    }
    cout<<maxd<<' '<<maxx<<endl;
    return 0;
}

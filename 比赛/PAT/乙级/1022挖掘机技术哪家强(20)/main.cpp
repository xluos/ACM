#include <bits/stdc++.h>

using namespace std;
int xue[100005];
int main()
{
    set<int>se;
    int n,xveid,maxx=0;
    cin>>n;
    while(n--)
    {
        int id,fen;
        scanf("%d %d",&id,&fen);
        se.insert(id);
        xue[id]+=fen;
    }
    for(set<int>::iterator it=se.begin();it!=se.end();it++)
    {
        if(xue[*it]>maxx)
        {
            xveid=*it;
            maxx=xue[*it];
        }
    }
    cout<<xveid<<' '<<maxx<<endl;
    return 0;
}

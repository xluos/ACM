#include <bits/stdc++.h>

using namespace std;
struct node{
    string name;
    int h;
};
int cmp(node a,node b)
{
    if(a.h==b.h)
        return a.name<b.name;
    return a.h>b.h;
}
void outhang(int begin,int end,node ren[])
{
    list<string>lis;
    for(int i=begin,k=1;i<end;i++,k++)
    {
        if(k%2)
            lis.push_back(ren[i].name);
        else
            lis.push_front(ren[i].name);
    }
    cout<<lis.front();lis.pop_front();
    for(list<string>::iterator it=lis.begin();it!=lis.end();it++)
        cout<<' '<<*it;
    cout<<endl;
}
int main()
{
    int n,k;
    node ren[10005];
    cin>>n>>k;k=n/k;
    for(int i=0;i<n;i++)
    {
        cin>>ren[i].name>>ren[i].h;
    }
    sort(ren,ren+n,cmp);
    int t=n%k;
    outhang(0,k+t,ren);
    for(int i=k+t;i<n;i+=k)
        outhang(i,i+k,ren);
    return 0;
}

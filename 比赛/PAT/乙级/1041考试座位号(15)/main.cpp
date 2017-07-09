#include <bits/stdc++.h>

using namespace std;
struct node
{
    string id;
    int zw;
}a[1005];
int main()
{
    int n,sj,zw;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s>>sj>>zw;
        a[sj].id=s;
        a[sj].zw=zw;
    }
    cin>>n;
    while(n--)
    {
        cin>>sj;
        cout<<a[sj].id<<' '<<a[sj].zw<<endl;
    }
    return 0;
}

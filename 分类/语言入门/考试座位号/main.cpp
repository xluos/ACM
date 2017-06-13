#include <iostream>
#include <stdio.h>
using namespace std;
struct hm{
    string s;
    int num;
};
int main()
{
    int w,t;
    hm h[1009];
    cin>>w;
    while(w--)
    {
        string s;int num,n;
        cin>>s>>n>>num;
        h[n].s=s;h[n].num=num;
    }
    cin>>w;
    while(w--)
    {
        cin>>t;
        cout<<h[t].s<<' '<<h[t].num<<endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s,s2,ans;
    cin>>s>>ans;
    s+=ans;
    cin>>s2;
    sort(s.begin(),s.end());
    sort(s2.begin(),s2.end());
    if(s==s2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if((n%100&&n%4==0)||n%400==0) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}

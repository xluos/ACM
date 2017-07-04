#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char ch;
    cin>>n>>ch;
    for(int i=0;i<n;i++)
        cout<<ch;
    cout<<endl;
    for(int j=0;j<(int)(n/2.0+0.5)-2;j++)
    {
        for(int i=0;i<n;i++)
            printf("%c",i==0||i==n-1?ch:' ');
        cout<<endl;
    }
    for(int i=0;i<n;i++)
        cout<<ch;
    cout<<endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d,n,j=0,y=0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        int ans=a+c;
        if(ans==b&&ans!=d) y++;
        else if(ans!=b&&ans==d) j++;
    }
    cout<<j<<' '<<y<<endl;
    return 0;
}

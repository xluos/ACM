#include <bits/stdc++.h>

using namespace std;

int main()
{
    string pw,s;
    int n;
    cin>>pw>>n;getchar();
    while(n--)
    {
        getline(cin,s);
        if(s=="#") return 0;
        if(s==pw)
        {
            cout<<"Welcome in"<<endl;
            return 0;
        }
        else cout<<"Wrong password: "<<s<<endl;
    }
    cout<<"Account locked"<<endl;
    return 0;
}

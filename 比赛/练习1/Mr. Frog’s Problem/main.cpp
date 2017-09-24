#include <iostream>

using namespace std;

int main()
{
    int n;
    long long a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<":"<<endl;
        cin>>a>>b;
        if(a==b){
            cout<<1<<endl<<a<<' '<<b<<endl;
        }
        else
        {
            if(b<a) swap(a,b);
            cout<<2<<endl;
            cout<<a<<' '<<b<<endl;
            cout<<b<<' '<<a<<endl;
        }
    }
    return 0;
}

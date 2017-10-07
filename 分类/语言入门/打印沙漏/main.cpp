#include <iostream>

using namespace std;
void hang(int n,char c)
{
    while(n--)
        cout<<c;
    cout<<endl;
}
void hang(int n)
{
    while(n--)
        cout<<' ';
}

int main()
{
    int n,i,sum=1;
    char c;
    cin>>n>>c;
    for(i=3;sum<=n;i+=2)
        sum+=i*2;
    i-=2;sum-=i*2;i-=2;
    for(int j=i;j>1;j-=2)
    {
        hang((i-j)/2);
        hang(j,c);
    }
    for(int j=1;j<=i;j+=2)
    {
        hang((i-j)/2);
        hang(j,c);
    }

    cout<<n-sum<<endl;
    return 0;
}

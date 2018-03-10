#include <iostream>

using namespace std;
char *s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void puti(int n,int m)
{
    for(int i = n;i>0&&n-i<m;i--)
    {
        cout<<s[i];
    }
}
void putj(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        puti(i,m);
        putj(m-i);
        cout<<'\n';
    }
    return 0;
}

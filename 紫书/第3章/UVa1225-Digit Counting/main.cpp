#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    while(n--)
    {
        int a[10]={0};
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int k=i;
            while(k)
            {
                a[k%10]++;
                k/=10;
            }

        }
        for(int i=0;i<10;i++)
        {
            cout<<a[i];
            if(i==9)cout<<endl;
            else cout<<' ';
        }
    }
    return 0;
}

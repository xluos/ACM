#include <iostream>

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int a,b,sum=0,ans=1,;
        cin>>a>>b;
        while(a>b){
            ans=1;
            while(ans<<1<a);
            a=a-ans+1;
        }
    }
}
/*int main()
{
    int w;cin>>w;
    while(w--)
    {
        int a,b,sum=0;
        cin>>a>>b;
        for(int i=1;a>b;i<<=1)
        {
            if(a&1)
            {
                a++;
                sum+=i;
            }
            a>>=1;
        }
        cout<<sum<<endl;
    }
    return 0;
}*/

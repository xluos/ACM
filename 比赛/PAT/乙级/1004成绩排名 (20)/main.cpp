#include <iostream>

using namespace std;

int main()
{
    string name_max,xh_max,name_min,xh_min,s,s2;
    int max=-1,min=999,ans,n;
    cin>>n;
    while(n--)
    {
        cin>>s>>s2>>ans;
        if(ans>max)
        {
            max=ans;
            name_max=s;
            xh_max=s2;
        }
        if(ans<min)
        {
            min=ans;
            name_min=s;
            xh_min=s2;
        }
    }
    cout<<name_max<<' '<<xh_max<<endl<<name_min<<' '<<xh_min<<endl;
    return 0;
}

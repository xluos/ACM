#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        double t,l,d,r;
        int num;
        cin>>l>>d>>r;
        double ans=r*r-(d*d/4);
        t=2*sqrt(ans);
        if(t<1||ans<0){cout<<"impossible"<<endl;continue;}
        d=l/t;
        if(d==(int)d)num=d;
        else num=d+1;
        cout<<num<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,time;
    cin>>a>>b;
    time=(b-a)*1.0/100+0.5;
    int m=time/60;
    int h=m/60;
    m%=60;time%=60;
    printf("%02d:%02d:%02d\n",h,m,time);
    return 0;
}

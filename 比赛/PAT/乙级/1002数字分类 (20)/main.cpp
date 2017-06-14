#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin>>n;
    int a1=0,s1=0,a2=0,s2=0,a3=0,s3=0,a4=0,s4=0,a5=-0x3f3f3f3f,s5=0;
    while(n--)
    {
        int ans;
        cin>>ans;
        switch(ans%5)
        {
        case 0:
            if(!(ans%2))
            {
                a1+=ans;
                s1++;
            }
            break;
        case 1:
            if(!(s2%2))
            {
                a2+=ans;
            }
            else
            {
                a2-=ans;
            }
            s2++;
            break;
        case 2:
            {
                s3++;
            }
            break;
        case 3:
            {
                a4+=ans;
                s4++;
            }
            break;
        case 4:
            {
                a5=max(a5,ans);
                s5++;
            }
            break;
        }
    }
    if(!s1)
        cout<<'N'<<' ';
    else
        cout<<a1<<' ';
    if(!s2)
        cout<<'N'<<' ';
    else
        cout<<a2<<' ';
    if(!s3)
        cout<<'N'<<' ';
    else
        cout<<s3<<' ';
    if(!s4)
        cout<<'N'<<' ';
    else
        printf("%.1lf ",a4*1.0/s4);
    if(!s5)
        cout<<'N'<<endl;
    else
        cout<<a5<<endl;

    return 0;
}

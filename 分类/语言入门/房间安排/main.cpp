#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w;
    cin>>w;
    while(w--)
    {
        int max=-1,a[210]={0};
        int m;cin>>m;
        while(m--)
        {
            int t,b,c;
            cin>>t>>b>>c;
            for(int i=b;i<b+c;i++)
            {
                a[i]+=t;
            }
        }
        for(int i=0;i<208;i++)
        {
            if(a[i]>max)max=a[i];
        }
        cout<<max<<endl;
    }


    return 0;
}

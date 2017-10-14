#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w[200009],l[200009];
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&w[i],&l[i]);
            w[i+n] = w[i];
            l[i+n] = w[i];
        }
        int sum=0,t=0,maxx=0;
        for(int i=0;i<2*n-1;i++)
        {
            sum += w[i];
            sum -= l[i];
            t++;
            if(sum<0)
            {
                sum=0;
                t=0;
            }
            if(maxx<t) maxx = t;
            //cout<<"sum=="<<sum<<" t=="<<t<<endl;
        }
        if(maxx > n)maxx = n;
        cout<<maxx<<endl;
    }
    return 0;
}

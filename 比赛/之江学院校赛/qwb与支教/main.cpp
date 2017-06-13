#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,z;
    int n,num;
    while(~scanf("%d%d %d %d",&x,&y,&z,&n))
    {
        num=0;
        for(int i=1;num!=n;i++)
        {
            if(i%x==0||i%y==0||i%z==0)
            {
                continue;
            }
            num++;
            cout<<i<<' ';
        }
    }
    return 0;
}

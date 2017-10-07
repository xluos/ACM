#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n,m;
        cin>>n>>m;
        int x=m/2-n,y=n-x;
        if(x*4+y*2==m&&x>=0&&y>=0)
            printf("%d %d\n",y,x);
        else
            printf("No answer\n");
    }
    return 0;
}

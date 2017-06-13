#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int mp[2000000];
int main()
{
    int d,I;
    while(scanf("%d %d",&d,&I),d+I)
    {
        memset(mp,0,sizeof(mp));
        int n;
        while(I--){
        n=1;
        for(int i=0;i<d-1;i++)
            if(++mp[n]&1)n=2*n;
            else n=n*2+1;
        }
        printf("%d\n",n);
    }
    return 0;
}

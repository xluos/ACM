#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    char a[205],b[205],ab[410];
    int w;
    cin>>w;
    for(int t=0;t<w;t++)
    {
        cin>>a>>b>>ab;
        int ai,bi,abi,k;
        ai=bi=abi=0;
        int l=strlen(ab);
        for(int i=0;i<l;)
        {
            if(a[ai]==ab[i]||b[bi]==ab[i])
            {
                if(a[ai]==ab[i])
                {   ai++;i++;}
                if(b[bi]==ab[i])
                {   bi++;i++;}
                k=1;
            }
            else
            {
                k=0;
                break;
            }

        }
        printf("Data set %d: %s\n",t+1,k?"yes":"no");
    }
    return 0;
}

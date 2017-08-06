#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,num[3005],i,j;
    while(cin>>a>>b)
    {
        int mp[30005]={0};
        printf("%d/%d = %d.",a,b,a/b);
        a=a%b*10;
        for(i=1; !mp[a]; i++)
        {
            mp[a]=i;
            num[i]=a/b;
            a=a%b*10;
        }
        for(j=1; j<i; j++)
        {
            if(j==mp[a]) printf("(");
            if(j==51)
            {
                printf("...");
                break;
            }
            printf("%d",num[j]);
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n",i-mp[a]);
    }
    return 0;
}

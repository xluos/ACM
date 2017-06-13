#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w;
    cin>>w;
    while(w--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i+=2)
            printf("%d ",i);
        printf("\n\n");
        for(int i=2;i<=n;i+=2)
            printf("%d ",i);
        printf("\n\n");
    }
    return 0;
}

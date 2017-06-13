#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int min=100000,max=-1,ans;
    for(int i=0;i<5;i++)
    {
        cin>>ans;
        if(max<ans)max=ans;
        if(min>ans)min=ans;
    }
    printf("%d %d",min,max);
    return 0;
}

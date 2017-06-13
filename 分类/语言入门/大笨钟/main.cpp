#include <iostream>
#include <stdio.h>
using namespace std;

void input_Dang(int n)
{
    if(!n)printf("Only 12:00.  Too early to Dang.");
    while(n--)cout<<"Dang";
    cout<<endl;
}
int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    h -= 12;
    if(h<0)
    {
        h += 12;
        if(h<10&&m<10)
        printf("Only 0%d:0%d.  Too early to Dang.\n",h,m);
        if(h>=10&&m<10)
        printf("Only %d:0%d.  Too early to Dang.\n",h,m);
        if(h<10&&m>=10)
        printf("Only 0%d:%d.  Too early to Dang.\n",h,m);
        if(h>=10&&m>=10)
        printf("Only %d:%d.  Too early to Dang.\n",h,m);
    }
    else
        input_Dang(h+((m+59)/60));

    return 0;
}

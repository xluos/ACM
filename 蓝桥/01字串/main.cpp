#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    for(int i=0; i<2; i++)
    {
        for(int i1=0; i1<2; i1++)
        {
            for(int i2=0; i2<2; i2++)
            {
                for(int i3=0; i3<2; i3++)
                {
                    for(int i4=0; i4<2; i4++)
                    {
                        printf("%d%d%d%d%d\n",i,i1,i2,i3,i4);
                    }
                }
            }
        }
    }
    return 0;
}

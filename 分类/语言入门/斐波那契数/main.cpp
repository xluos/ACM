#include <iostream>
#include <stdio.h>
using namespace std;
int F[22];
void init()
{
    F[1]=F[2]=1;
    for(int i=3;i<22;i++)
        F[i]=F[i-1]+F[i-2];
}
int main()
{
    init();
    int w,n;
    cin>>w;
    while(w--)
    {
        cin>>n;
        cout<<F[n]<<endl;
    }
    return 0;
}

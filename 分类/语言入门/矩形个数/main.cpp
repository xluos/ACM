#include<iostream>
using namespace std;
int main()
{
    long long m,n;
    while(cin>>m>>n)
    {
        long long l=0;
        l=m*(m+1)/2*n*(n+1)/2;//横向有1-m中取法，纵向有1-n种取法，所有举行的个数每一项相乘
        cout<<l<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define LL long long
using namespace std;
string name[]= {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main()
{
    long long n,sum=5;
    scanf("%I64d",&n);
    if(n<=5)
    {
        cout<<name[n-1]<<endl;
    }
    else
    {
        while(n>sum)
        {
            n-=sum;
            sum<<=1;
        }
        sum/=5;
        //cout<<sum<<endl;
        n=ceil(n*1.0/sum);
        //cout<<n<<endl;
        cout<<name[n-1]<<endl;
    }

    return 0;
}

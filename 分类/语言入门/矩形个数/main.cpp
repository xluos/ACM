#include<iostream>
using namespace std;
int main()
{
    long long m,n;
    while(cin>>m>>n)
    {
        long long l=0;
        l=m*(m+1)/2*n*(n+1)/2;//������1-m��ȡ����������1-n��ȡ�������о��еĸ���ÿһ�����
        cout<<l<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,p,a[100005],maxx=0;
    scanf("%lld %lld",&n,&p);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n-maxx;i++)
    {
        int ans=upper_bound(a+i,a+n,a[i]*p)-a;//��Ϊ���ҵ����ǵ�һ�����ڲ���ֵ�ĵ�ַ��������һ������<=a[i]*p��
        if(ans-i>maxx)//Ȼ��ans-i���ǵ�i����ans��֮�������
            maxx=ans-i;
    }
    cout<<maxx<<endl;
    return 0;
}

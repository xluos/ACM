#include <iostream>
#include <bits/stdc++.h>
//#define N 500000001
using namespace std;
//int a[N],b[N];
int _1_num(int n)
{
    int sum=0;
    while(n)
    {
        if(n%10==1)
            sum++;
        n/=10;
    }
    return sum;
}
int main()
{
//    a[1]=1;
//    for(int i=2;i<N;i++)
//    {
//        a[i]=a[i-1]+_1_num(i);
//    }
//    b[0]=a[N-1];
//    for(int i=N;i<1000000000;i++)
//    {
//        b[i-N+1]=b[i-N]+_1_num(i);
//    }
    int n,sum=0;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        sum+=_1_num(i);
    }
    cout<<sum<<endl;
    return 0;
}
/**
#include<stdio.h>

long long int Count(long long int n){
    //1的个数
    long long int count = 0;
    //当前位
    long long int Factor = 1;
    //低位数字
    long long int LowerNum = 0;
    //当前位数字
    long long int CurrNum = 0;
    //高位数字
    long long int HigherNum = 0;
    if(n <= 0){
        return 0;
    }
    while(n / Factor != 0){
        //低位数字
        LowerNum = n - (n / Factor) * Factor;
        //当前位数字
        CurrNum = (n / Factor) % 10;
        //高位数字
        HigherNum = n / (Factor * 10);
        //如果为0,出现1的次数由高位决定
        if(CurrNum == 0){
            //等于高位数字 * 当前位数
            count += HigherNum * Factor;
        }
        //如果为1,出现1的次数由高位和低位决定
        else if(CurrNum == 1){
            //高位数字 * 当前位数 + 低位数字 + 1
            count += HigherNum * Factor + LowerNum + 1;
        }
        //如果大于1,出现1的次数由高位决定
        else{
            //（高位数字+1）* 当前位数
            count += (HigherNum + 1) * Factor;
        }
        //前移一位
        Factor *= 10;
    }
    return count;
}

int main(){
    long long int a;
    while(scanf("%lld",&a) != EOF){
        printf("%lld\n",Count(a));
    }
    return 0;
}
*/

#include <iostream>

using namespace std;
//int summ;
//void bfs(int n,int x)
//{
//    if(n>=x)
//    {
//        if(n==x)
//            summ++;
//        return;
//    }
//    for(int i=1;i<4;i++)
//    {
//        n+=i;
//        bfs(n,x);
//        n-=i;
//    }
//}
int b[22]={1,2,4,7,13,24,44,81,149,274,504,927,1705,3136,5768,10609,19513,35890,66012,121415};
int main()
{
    int w;cin>>w;
//    for(int i=1;i<=20;i++)
//    {
//        summ=0;
//        bfs(0,i);
//        b[i]=summ;
//        cout<<b[i]<<endl;
//    }
    while(w--)
    {
        long long n,ans,sum=1;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>ans;
            sum*=b[ans-1];
            if(sum>10007)
                sum%=10007;
        }
        cout<<sum<<endl;
    }

    return 0;
}

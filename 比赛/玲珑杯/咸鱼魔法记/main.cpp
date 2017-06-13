#include <bits/stdc++.h>
using namespace std;
int a[300006];
int main()
{
    int n,k,max=0;
    cin>>n>>k;
    cin>>a[0];
    a[0]=!a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        a[i]=!a[i];
        a[i]+=a[i-1];
    }
    for(int i=k;i<n;i++)
    {
        for(int j=0;j<i-k;j++)
        {
            if((i-j)>max&&(a[i]-a[j])<=k)
                max=i-j;
        }
    }
    cout<<max<<endl;
    return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//int a[300006];
//int main()
//{
//    int n,k,t=0,maxx=0;
//    int l=0,r=0,sum=0;
//    cin>>n>>k;
//    for(int i=0;i<n;i++)
//    {
//        cin>>a[i];
//        a[i]=!a[i];
//    }
//    while(l<n)
//    {
//        while(r<n&&sum<=k)
//        {
//            sum+=a[r];
//            r++;
//        }
//        r--;
//        sum-=a[r];
//        maxx=max(maxx,r-l);
//        sum-=a[l];
//        l++;
//    }
//    cout<<maxx<<endl;
//    return 0;
//}

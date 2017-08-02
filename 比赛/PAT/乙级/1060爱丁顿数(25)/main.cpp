#include <bits/stdc++.h>

using namespace std;
int a[100005]={0};
int cmp(int a,int b){return a>b;}
int main()
{
    int n,e=0;cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(a[i]>i+1) e=i+1;
        else break;
    }
    cout<<e<<endl;
    return 0;
}

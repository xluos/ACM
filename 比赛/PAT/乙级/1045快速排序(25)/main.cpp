#include <bits/stdc++.h>
#define INF 1000000005
using namespace std;

int main()
{
    int n,a[100005],j=0,b[100005],minn;
    map<int,int>mp;
    priority_queue<int,vector<int>,greater<int> >q;
    q.push(INF);
    cin>>n;
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        q.push(a[i]);

    }
    minn=a[0];
    mp[a[0]]=1;
    for(int i=0;i<n;i++)
    {
        int top=q.top();
//        cout<<"top="<<top<<' ';
//        cout<<"minn="<<minn<<endl;;
        if(a[i]>=minn&&a[i]<=top)
        {
            b[j++]=a[i];
        }
        if(a[i]>minn)
        {
            minn=a[i];
            mp[minn]=1;
        }
        if(a[i]==q.top())
        {
            q.pop();
            while(mp[q.top()])
                q.pop();
        }
    }
    sort(b,b+j);
    cout<<j<<endl;
    for(int i=0;i<j-1;i++)
    {
        cout<<b[i]<<' ';
    }
    cout<<b[j-1]<<endl;
    return 0;
}











/*
#include <bits/stdc++.h>
#define INF 1000000005
using namespace std;
int judeg(int a[],int k,int n)
{
    for(int i=k;i>=0;i--)
        if(a[i]>a[k])return 0;
    for(int i=k;i<n;i++)
        if(a[i]<a[k])return 0;
    return 1;
}
int main()
{
    int n,a[100005],j=0,b[100005],minn;
    cin>>n;
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(judeg(a,i,n))
        {
            b[j++]=a[i];
        }
    }
    sort(b,b+j);
    cout<<j<<endl;
    for(int i=0;i<j-1;i++)
    {
        cout<<b[i]<<' ';
    }
    cout<<b[j-1]<<endl;
    return 0;
}
*/

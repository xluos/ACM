#include <bits/stdc++.h>

using namespace std;
struct node{
    int id,de,ca,lei,zong;
};
int cmp(node a,node b)
{
    if(a.lei==b.lei)
    {
        if(a.zong==b.zong)
        {
            if(a.de==b.de)
                return a.id<b.id;
            return a.de>b.de;
        }
        return a.zong>b.zong;
    }
    return a.lei<b.lei;
}
int main()
{
    int sum=0,n,l,h;
    node a[100005],ans;
    cin>>n>>l>>h;
    while(n--)
    {
        scanf("%d %d %d",&ans.id,&ans.de,&ans.ca);
        if(ans.ca>=l&&ans.de>=l)
        {
            ans.zong=ans.ca+ans.de;
            if(ans.de>=h)
            {
                if(ans.ca>=h)
                    ans.lei=1;
                else
                    ans.lei=2;
            }
            else
            {
                if(ans.de>=ans.ca)
                    ans.lei=3;
                else
                    ans.lei=4;
            }
            a[sum++]=ans;
        }
    }
    sort(a,a+sum,cmp);
    cout<<sum<<endl;
    for(int i=0;i<sum;i++)
    {
        printf("%d %d %d\n",a[i].id,a[i].de,a[i].ca);
    }
    return 0;
}

#include <bits/stdc++.h>
#pragma comment(linker, ¡°/STACK:1024000000,1024000000¡±)
#define N 100005
using namespace std;
//struct node{
//    double x,y;
//}no[N];
pair<double,double>no[N];
//bool cmp(node a,node b)
//{
//    if(a.first>=b.first||a.second>=b.second)
//        return false;
//    else
//        return true;
//}
bool sort_cmp(pair<double,double> a,pair<double,double> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int Search(pair<double,double> b[],pair<double,double> num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num.second>b[mid].second) low=mid+1;
        else    high=mid-1;
    }
    return low;
}
int lis(pair<double,double> a[],int n)
{
    int k=1;
    pair<double,double> vis[N];
    vis[0]=a[0];
    for(int i=1; i<n; i++)
    {cout<<a[i].first<<' '<<vis[k-1].first<<' '<<a[i].second<<' '<<vis[k-1].second<<"  aaaa"<<endl;
        if(a[i].second>vis[k-1].second&&a[i].first>vis[k-1].first)
        //if(a[i]>vis[k-1])
        {

                vis[k++]=a[i];
                cout<<vis[k-1].first<<' '<<vis[k-1].second<<"  sss"<<endl;
        }
        else
        {
            //int mid=lower_bound(vis,vis+k,a[i])-vis;
            int mid=Search(vis,a[i],0,k);
            vis[mid]=a[i];
            cout<<vis[mid].first<<' '<<vis[mid].second<<"  abs"<<mid<<endl;
        }
        for(int abc=0;abc<k;abc++)
            cout<<vis[abc].first<<' '<<vis[abc].second<<"                              111"<<endl;

    }
    return k;
}
int main()
{
    int T;cin>>T;
    while(T--)
    {
        double k1,k2;
        int l[N];
        int a,b,c,d,n,p=0;
        scanf("%d",&n);
        scanf("%d %d %d %d",&a,&b,&c,&d);
        k1=a*1.0/b;k2=c*1.0/d;
        if(k1>k2)swap(k1,k2);
        for(int i=0;i<n;i++)
        {
            double ans;
            scanf("%d%d",&a,&b);
            ans=b*1.0/a;
            if(ans>k1&&ans<k2)
            {
                no[p].first=a*1.0-b*1.0/k2;
                no[p].second=b*1.0-k1*a;
                l[p]=1;
                p++;
                //cout<<no[p-1].first<<' '<<no[p-1].second<<"  a"<<endl;
            }
        }
        sort(no,no+p,sort_cmp);
//        for(int i=1;i<p;i++)
//        {
//            for(int j=0;j<i;j++)
//            {
//                if(no[i].first>no[j].first&&no[i].second>no[j].second&&l[j]+1>l[i])
//                {
//                    //cout<<no[i].first<<' '<<no[j].first<<' '<<no[i].second<<' '<<no[j].second<<endl;
//                    l[i]=l[j]+1;
//                }
//            }
//        }
//        cout<<l[p-1]<<endl;
        cout<<lis(no,p)<<endl;
    }
    return 0;
}

//#include <bits/stdc++.h>
//#define N 100005
//using namespace std;
//struct node{
//    double x,y;
//}no[N];
//bool sort_cmp(node a,node b)
//{
//    if(a.first==b.first)
//        return a.second<b.second;
//    return a.first<b.first;
//}
//int Search(node b[],node num,int low,int high)
//{
//    int mid;
//    while(low<=high)
//    {
//        mid=(low+high)/2;
//        if(num.second>b[mid].second) low=mid+1;
//        else    high=mid-1;
//    }
//    return low;
//}
//int lis(node a[],int n)
//{
//    int k=1;
//    node vis[N];
//    vis[0]=a[0];
//    for(int i=1; i<n; i++)
//    {
//        if(a[i].second>vis[k-1].second&&a[i].first>vis[k-1].first)
//                vis[k++]=a[i];
//        else
//        {
//            int mid=Search(vis,a[i],0,k);
//            vis[mid]=a[i];
//        }
//    }
//    return k;
//}
//int main()
//{
//    int T;cin>>T;
//    while(T--)
//    {
//        double k1,k2;
//        int l[N];
//        int a,b,c,d,n,p=0;
//        scanf("%d",&n);
//        scanf("%d %d %d %d",&a,&b,&c,&d);
//        k1=a*1.0/b;k2=c*1.0/d;
//        if(k1>k2)swap(k1,k2);
//        for(int i=0;i<n;i++)
//        {
//            double ans;
//            scanf("%d%d",&a,&b);
//            ans=b*1.0/a;
//            if(ans>k1&&ans<k2)
//            {
//                no[p].first=a*1.0-b*1.0/k2;
//                no[p].second=b*1.0-k1*a;
//                l[p]=1;
//                p++;
//            }
//        }
//        sort(no,no+p,sort_cmp);
//        cout<<lis(no,p)<<endl;
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <map>
#define N 10005
using namespace std;
int pre[N],t[N];
int Find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void mix(int i,int j)
{
    int fx=Find(i),fy=Find(j);
    if(fx!=fy)
    {
        pre[fy]=fx;
    }
}
int main()
{
    int a,b;
    set<int>se;
    map<int,int>mp;
    int sum=0,T=1;
    //init();
    while(cin>>a>>b)
    {

        if(a==b&&a==-1)
            break;
        if(a==b&&a==0)
        {
            cout<<"Case "<<T++;
            if(sum==0)
            {
                cout<<" is a tree."<<endl;
                continue;
            }
            int flag=0,flag_t=0;
            set<int>::iterator it;
            memset(t,0,sizeof(t));
            for(it=se.begin();it!=se.end();it++)
            {
                if(mp[*it]==0)
                {
                    flag++;
                }
                t[Find(*it)]=1;
            }
            for(it=se.begin();it!=se.end();it++)
            {
                if(t[*it]==1)
                {
                    flag_t++;
                }

            }
           // cout<<flag<<' '<<flag_t<<' '<<sum<<' '<<se.size()<<' '<<endl;;
            if(flag==1&&flag_t==1&&sum==se.size()-1)
                cout<<" is a tree."<<endl;
            else
                cout<<" is not a tree."<<endl;
            se.clear();
            mp.clear();
            sum=0;
            memset(pre,0,sizeof(pre));
            continue;
        }
        sum++;
        pre[a]=a;pre[b]=b;
        se.insert(a);
        se.insert(b);
        mp[b]++;
        mix(a,b);
    }
    return 0;
}

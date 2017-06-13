#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[10],d[2]={-1,1};
int Judge(int n)
{
    stringstream ss;string s;
    ss<<n;ss>>s;
    for(int i=0;i<s.length();i++)
    {
        if(a[s[i]-'0'])
            return 0;
    }
    return 1;
}
struct Node
{
    int x,step;
};
int main()
{
    int n,s,t;
    while(~scanf("%d %d %d",&n,&s,&t))
    {
        int sum=0;int x;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);a[x]=1;
        }
        if(Judge(t))
        {
          stringstream ss;ss<<t;string s;ss>>s;
           printf("%d\n",s.length());
           //continue;
        }
        else
        {
            int temp;
            int i;
            for(i=1;;i++)
            {
               if(Judge(t-i)||t-i==s)
               {
                   temp=t-i;
                   break;
               }
               if(Judge(t+i)||t+i==s)
               {
                   temp=t+i;
                   break;
               }

            }
            if(temp!=s)
            {
                stringstream ss;ss<<temp;string s;ss>>s;
                i+=s.length();
            }
            printf("%d\n",i);
        }

    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
int change(string s,int &r,int &c)
{
    int n;
    stringstream ss(s);
    ss>>s;
    if(s=="DR")
    {
        ss>>n;
        int ans,t=0;
        for(int i=0;i<n;i++)
        {
            ss>>ans;
            if(ans<r) t++;
            else if(ans==r) return 1;
        }
        r-=t;
    }
    else if(s=="DC")
    {
        ss>>n;
        int ans,t=0;
        for(int i=0;i<n;i++)
        {
            ss>>ans;
            if(ans<c) t++;
            else if(ans==c) return 1;
        }
        c-=t;
    }
    else if(s=="IR")
    {
        ss>>n;
        int ans,t=0;
        for(int i=0;i<n;i++)
        {
            ss>>ans;
            if(ans<=r) t++;
        }
        r+=t;
    }
    else if(s=="IC")
    {
        ss>>n;
        int ans,t=0;
        for(int i=0;i<n;i++)
        {
            ss>>ans;
            if(ans<=c) t++;
        }
        c+=t;
    }
    else if(s=="EX")
    {
        int x,y,x2,y2;
        ss>>x>>y>>x2>>y2;
        if(r==x&&c==y) r=x2,c=y2;
        else if(r==x2&&c==y2) r=x,c=y;
    }
    return 0;
}
int main()
{
    int r,c,n,p=1;
    string s;
    while(scanf("%d%d",&r,&c),r+c)
    {
        if(p>1)printf("\n");
        printf("Spreadsheet #%d\n",p++);
        vector<string>ve;
        cin>>n;getchar();
        while(n--)
        {
            getline(cin,s);
            ve.push_back(s);
        }
        cin>>n;
        while(n--)
        {
            int a,b,i;
            cin>>a>>b;
            printf("Cell data in (%d,%d) ",a,b);
            for(i=0;i<ve.size();i++)
            {
                if(change(ve[i],a,b)) break;
            }

            if(i!=ve.size()) printf("GONE\n");
            else printf("moved to (%d,%d)\n",a,b);
        }

    }
    return 0;
}

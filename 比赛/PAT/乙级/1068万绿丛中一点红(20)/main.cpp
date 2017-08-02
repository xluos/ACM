#include <bits/stdc++.h>

using namespace std;
int mn[1002][1002];
int dir[8][2]={-1,1,0,1,1,1,-1,0,1,0,-1,-1,0,-1,1,-1};
int main()
{
    int n,m,TOL,X,Y,color,flag=1;
    map<int,int>mp;
    cin>>m>>n>>TOL;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mn[i][j]);
            mp[mn[i][j]]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int TolOk=1;
            if(mp[mn[i][j]]>1) continue;
            for(int k=0;k<8;k++)
            {
                int x=i+dir[k][0],y=j+dir[k][1];
                if(x>=0&&x<n&&y>=0&&y<m)
                {
                    if(abs(mn[x][y]-mn[i][j])<=TOL) {TolOk=0;break;}
                }
            }
            //cout<<mn[i][j]<<'\t';
            if(TolOk)
            {
                if(flag)
                {
                    X=i+1;Y=j+1;color=mn[i][j];
                    flag=0;
                }
                else
                {
                    cout<<"Not Unique"<<endl;
                    //cout<<i<<' '<<j<<mn[i][j]<<endl;;
                    return 0;
                }
            }
        }
        //cout<<endl;
    }
    if(flag) cout<<"Not Exist"<<endl;
    else cout<<'('<<X<<", "<<Y<<"): "<<color<<endl;
    return 0;
}

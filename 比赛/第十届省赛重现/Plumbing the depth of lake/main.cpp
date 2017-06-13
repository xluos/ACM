#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dir[8][2]={-1,-1, -1,0, -1,1, 1,0, 1,1, 1,-1, 0,1, 0,-1};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        int mymap[55][55]={0};
        for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++)
            cin>>mymap[i][j];
         int small=-1;
         for(int i=1;i<n;i++)
         {
              for(int j=1;j<m;j++)
              {
                  for(int k=0;k<8;k++)
                  {
                      if(mymap[i][j]==mymap[i+dir[k][0]][j+dir[k][1]])
                      small=max(small,mymap[i][j]);
                  }
              }
         }
         cout<<small<<endl;
    }
    return 0;
}

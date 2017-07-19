#include <bits/stdc++.h>

using namespace std;
int dan,shuang,can;
int main()
{
    int n,ans,sum=0;
    cin>>n>>dan>>shuang;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ans);
        if(ans==1)
        {
            if(dan>0) dan--;
            else if(shuang>0)
            {
                shuang--;
                can++;
            }
            else if(can>0) can--;
            else sum+=1;
        }
        else
        {
            if(shuang>0) shuang--;
            else sum+=2;
        }
    }
    cout<<sum<<endl;
    return 0;
}

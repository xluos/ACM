#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
struct gl{
    double gl;
    int s;
};
map<int,gl>mp;
double gongli(int n,double r)
{
    if(mp[n].gl!=0)
        return mp[n].gl;
    mp[n].gl=gongli(mp[n].s,r)*(1-r/100);
    return mp[n].gl;
}
int main()
{
    int n;
    double sum=0,r,z;
    cin>>n>>z>>r;
    mp[0].gl=z;
    for(int i=0;i<n;i++)
    {
        int ans;cin>>ans;
        if(ans==0){
            int t;cin>>t;
            sum+=gongli(i,r)*t;
        }
        while(ans--)
        {
            int t;cin>>t;
            mp[t].s=i;
        }
    }
    sum=(int)sum;
    printf("%.0lf\n",sum);

    return 0;
}

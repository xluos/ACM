#include <bits/stdc++.h>

using namespace std;
bool isPrime(int num)
{
    if (num == 2 || num == 3)
    {
        return true;
    }
    if (num % 6 != 1 && num % 6 != 5)
    {
        return false;
    }
    for (int i = 5; i <= sqrt(num); i += 6)
    {
        if (num % i == 0 || num % (i+2) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n,ans;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>ans;
        mp[ans]=i+1;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ans;
        printf("%04d: ",ans);
        if(mp[ans]==1) {printf("Mystery Award\n");mp[ans]=-1;}
        else if(mp[ans]==0) printf("Are you kidding?\n");
        else if(isPrime(mp[ans])) {printf("Minion\n");mp[ans]=-1;}
        else if(mp[ans]==-1) printf("Checked\n");
        else {printf("Chocolate\n");mp[ans]=-1;}

    }
    return 0;
}

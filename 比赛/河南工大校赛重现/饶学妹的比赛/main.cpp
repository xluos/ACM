#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct ren{
    char name[22];
    int wa_sum[11];
    int ac_yes[11];
    double time;
    int id;
    int ac_sum;
    ren()
    {
        for(int i=0;i<11;i++)
        {
            wa_sum[i]=0;
            ac_yes[i]=0;
        }
        time=0;
        ac_sum=0;
    }
};
ren *Ren=new ren[1005];
bool cmp(ren a,ren b)
{
    if(a.ac_sum==b.ac_sum)
        if(a.time==b.time)
            return a.id<b.id;
        else
            return a.time<b.time;
    else
        return a.ac_sum>b.ac_sum;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",Ren[i].name);
        Ren[i].id=i;

    }
    for(int i=0;i<m;i++)
    {
        int time,id,pid;
        char res[3];
        scanf(" %d %d %d %s",&time,&id,&pid,res);
        if(res[0]=='A'&&!Ren[id].ac_yes[pid])
        {
            Ren[id].time+=time+Ren[id].wa_sum[pid]*20;
            Ren[id].ac_yes[pid]=1;
            Ren[id].ac_sum++;
        }
        if(res[0]=='W'&&!Ren[id].ac_yes[pid])
        {
            Ren[id].wa_sum[pid]++;
        }
    }
    sort(Ren+1,Ren+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        printf("%s %d %.0lf\n",Ren[i].name,Ren[i].ac_sum,Ren[i].time);
    }
    return 0;
}

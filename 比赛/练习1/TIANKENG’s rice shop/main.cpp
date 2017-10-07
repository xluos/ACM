#include <bits/stdc++.h>

using namespace std;
struct people{
    int time;
    int type;
    int num;
};
int getminute(char *str)
{
    int hour,minute;
    sscanf(str,"%d:%d",&hour,&minute);
    return hour*60+minute;
}
void puttime(int n)
{
    int hour,minute;
    hour = n/60;
    minute = n%60;
    printf("%02d:%02d\n",hour%24,minute);
}
int main()
{
    int w;
    people pp[1006];
    scanf("%d",&w);
    while(w--)
    {
        int n,t,k,m,timeplus=0;
        scanf("%d %d %d %d",&n,&t,&k,&m);
        for(int i=0;i<m;i++)
        {
            char s[10];
            int num,type;
            scanf("%s %d %d",s,&type,&num);
            pp[i].time = getminute(s);
            pp[i].num = num;
            pp[i].type = type;
        }
        int id = -1,surplus=0;
        for(int i=0;i<m;i++)
        {
            if(pp[i].type==id)
            {
                pp[i].num -= surplus;
            }
            else
            {
                surplus = 0 ;
            }
            id = pp[i].type;
            surplus = k - pp[i].num % k ;
            int ans = pp[i].num / k + ceil( ( pp[i].num % k ) / k ) ;
            cout<< ans <<endl;
            timeplus += ans * t;
            puttime(pp[i].time + timeplus);
        }
        if(w) printf("\n");
    }

    return 0;
}

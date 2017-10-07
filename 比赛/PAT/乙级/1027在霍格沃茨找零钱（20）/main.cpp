#include <bits/stdc++.h>

using namespace std;

int main()
{
    int G,S,K,GSK_sum=0,g,s,k,gsk_sum=0;
    scanf("%d.%d.%d %d.%d.%d",&g,&s,&k,&G,&S,&K);
    GSK_sum=(G*17+S)*29+K;
    gsk_sum=(g*17+s)*29+k;
    GSK_sum-=gsk_sum;
    if(GSK_sum<0){GSK_sum=-GSK_sum;printf("-");}
    K=GSK_sum%29;
    S=(GSK_sum/29)%17;
    G=(GSK_sum/29)/17;
    printf("%d.%d.%d\n",G,S,K);
    return 0;
}

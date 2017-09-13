#include <bits/stdc++.h>

using namespace std;
string shu[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
int main()
{
    char ch,num[100];
    int sum=0;
    while(~scanf("%c",&ch)&&ch!='\n')
    {
        sum+=ch-'0';
    }
    sprintf(num,"%d",sum);
    cout<<shu[num[0]-'0'];
    for(int i=1;i<strlen(num);i++)
    {
        cout<<' '<<shu[num[i]-'0'];
    }
    cout<<endl;
    return 0;
}

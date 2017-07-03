#include <bits/stdc++.h>

using namespace std;
int quan[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char jiao[]={'1','0','X','9','8','7','6','5','4','3','2'};
int judeg(char s[])
{
    int sum=0;
    for(int i=0;i<17;i++)
        if(s[i]<'0'||s[i]>'9')
            return 0;
        else
        {
            sum+=(s[i]-'0')*quan[i];
        }
    sum%=11;
    if(jiao[sum]==s[17])
        return 1;
    return 0;
}
int main()
{
    char id[20];
    int n,flag=1;
    cin>>n;getchar();
    while(n--)
    {
        scanf("%s",id);
        if(!judeg(id))
        {
            flag=0;
            printf("%s\n",id);
        }
    }
    if(flag)printf("All passed\n");
    return 0;
}
/**
4
320124198808240056
12010X198901011234
110108196711301866
37070419881216001X
*/

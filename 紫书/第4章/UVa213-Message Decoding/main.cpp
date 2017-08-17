#include <bits/stdc++.h>

using namespace std;
int getnum(int n)
{
    int num=0,flag=0;
    char ch;
    while(n)
    {
        if(ch!='0'&&ch!='1') continue;
        if(ch=='0') flag=1;
        num<<=1;
        num+=ch-'0';
        n--;
    }
    if(flag)
        return num;
    else
        return -1;
}
int main()
{
    char ch[100000];
    while(gets(ch))
    {
        vector<vector<char> >ve;
        int n,k=0;
        for(int i=1;ch[k]; i++)
        {
            vector<char>vee;
            for(int j=0; j<pow(2,i)-1; j++,k++)
            {
                if(!ch[k]) break;
                vee.push_back(ch[k]);
            }
            ve.push_back(vee);
        }
        while(n=getnum(3),n)
        {
            int ans;
            while(ans=getnum(n),~ans)
            {
                printf("%c",ve[n-1][ans]);
            }
        }
        printf("\n");
        getchar();
    }
    return 0;
}

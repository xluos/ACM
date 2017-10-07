#include <bits/stdc++.h>

using namespace std;
char ve[8][1<<9+1];
char getcha()
{
    int ch;
    while(ch=getchar())
    {
        if(ch!='\n'&&ch!='\t') return ch;
    }
}
int getnum(int n)
{
    int num=0;
    while(n--) num=num*2+getcha()-'0';
    return num;
}
int gethead()
{
    char ch[100001];
    int k=0;
    memset(ve,0,sizeof(ve));
    if(scanf("%[^\n]",ch)==-1) return 0;
    for(int i=1;;i++)
    {
        for(int j=0;j<(1<<i)-1;j++,k++)
        {
            if(!ch[k]) return 1;
            ve[i][j]=ch[k];
        }
    }
    return 1;
}
int main()
{
    int n;
    while(gethead())
    {
        while(n=getnum(3),n)
        {
            int ans;
            while(1)
            {
                ans=getnum(n);
                if(ans==(1<<n)-1)break;
                printf("%c",ve[n][ans]);
            }
        }
        printf("\n");
        getchar();
    }
}


































/*#include <bits/stdc++.h>

using namespace std;
char ve[8][1<<9+1];
int getnum(int n)
{
    int num=0,flag=0;
    char ch;
    //cout<<"ch=";
    while(n)
    {
        if(!~scanf("%c",&ch)) return -1;
        if(ch!='0'&&ch!='1') continue;
        if(ch=='0') flag=1;
        num<<=1;
        //cout<<ch;
        num+=ch-'0';
        n--;
    }
    //cout<<'*'<<endl;
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
        //vector<vector<char> >ve;
        memset(ve,0,sizeof(ve));
        int n,k=0,x=0;
        for(int i=1;ch[k]; i++)
        {
            //vector<char>vee;
            for(int j=0; j<pow(2,i)-1; j++,k++)
            {
                 if(!ch[k]) break;
                //vee.push_back(ch[k]);
                ve[i][j]=ch[k];
            }
            //ve.push_back(vee);
            x++;
        }
//        cout<<x;
//        for(int i=0;i<x;i++)
//        {
//            for(int j=0;j<(1<<i)-1;j++)
//            {
//                cout<<ve[i][j];
//            }
//            cout<<'*'<<endl;
//        }
        while(n=getnum(3),n&&~n)
        {
            int ans;
            //cout<<"n="<<n<<endl;
            while(ans=getnum(n),~ans)
            {
                //cout<<"ans="<<ans<<endl;
                printf("%c",ve[n][ans]);
            }
        }
        printf("\n");
        getchar();
    }
    return 0;
}
*/

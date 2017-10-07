#include <bits/stdc++.h>

using namespace std;
int find(int n)
{
        int i=0,m,flag=0,ans,S=-1;
        char ch;
        map<int,int>mp;
        map<int,int>vis;
        for(i=0;i<n;i++)
        {
            scanf("%c",&ch);
            getchar();
            switch(ch)
            {
            case 'O':
                 scanf("%d",&ans);
                 getchar();
                if(mp[ans])
                {
                    mp[ans]--;
                }
                else
                {
                    if(flag)
                    {
                        flag--;
                    }
                    else
                    {
                        if(S==-1)
                            S=i+1;
                    }
                }
                break;
            case 'I':
                scanf("%d",&ans);
                getchar();
                if(!vis[ans])
                {
                    vis[ans]=1;
                    mp[ans]++;
                }
                else
                {
                    if(S==-1)
                        S=i+1;
                }
                break;
            case '?':
                flag++;
                break;
            }
        }
        return S;
}
int main()
{

    int n;
    while(~scanf("%d",&n))
    {
        getchar();
        cout<<find(n)<<endl;
    }

    return 0;
}
/**
0
1
O 1
2
?
O 1
3
I 1
?
O 1
2
I 2
O 1
*/

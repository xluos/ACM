#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    int vis;
}ans;
int flag,m;
vector<node>ve[26];
void dfs(int head)
{
//    cout<<head<<' '<<num<<' '<<ve[head][num].data<<endl;
    if(head == 12)
    {
        flag = 1;
        printf("Yes.\n");
        return ;
    }
    for(int i=0;i<ve[head].size();i++)
    {
        if(flag) return ;
        if(ve[head][i].vis) continue;
        ve[head][i].vis = 1;
        dfs(ve[head][i].data);
        ve[head][i].vis = 0;
    }
    return ;
}
void del()
{
    for(int i=0;i<26;i++)
        ve[i].clear();
}
int main()
{
    char s[1000];
    while(~scanf("%s",s))
    {
        if(s[0] == '0')
        {
            if(ve[1].size() > 0&&m) dfs(1);
            if(!flag) printf("No.\n");
            flag = 0;
            m = 0;
            del();
            continue;
        }
        ans.data = s[strlen(s)-1]-'a';
        ans.vis = 0;
        if(ans.data == 12) m = 1;
        ve[s[0]-'a'].push_back(ans);
    }
    return 0;
}

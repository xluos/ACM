#include <bits/stdc++.h>

using namespace std;
struct timu{
    int id,fen,t,zt,ok;
    string daan;
};
int cmp(timu a,timu b)
{
    if(a.ok==b.ok)
        return a.id<b.id;
    return a.ok>b.ok;
}
int main()
{
    int n,m,stm[1005]={0};
    timu ans;
    vector<timu>ve;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>ans.fen>>ans.t>>ans.zt;
        getchar();
        getline(cin,ans.daan);
        ans.id=i+1;ans.ok=n;
        ve.push_back(ans);
    }

    for(int i=0;i<n;i++)
    {
        string s;
        getline(cin,s);
        int head=0,till=0;
        for(int j=0;j<m;j++,head++,till++)
        {
            int k=0;
            while(s[head]!='(') head++;
            while(s[till]!=')') {till++;k++;}
            string dn=s.substr(head,k);
            if(dn[1]-'0'==ve[j].zt)
            {
                if(dn.substr(3,ve[j].zt*2-1)==ve[j].daan)
                {
                    stm[i]+=ve[j].fen;
                    ve[j].ok--;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<stm[i]<<endl;
    sort(ve.begin(),ve.end(),cmp);
    if(ve[0].ok==0) printf("Too simple\n");
    else
    {
        cout<<ve[0].ok;
        for(int i=0;i<m;i++)
        {
            if((ve[i].ok==ve[0].ok))cout<<' '<<ve[i].id;
            else break;
        }
    }
    return 0;
}
/*
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)

3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (1 b) (2 b c) (4 a b d e)
(2 a c) (1 b) (2 b c) (4 a b d e)
(2 a c) (1 b) (2 b c) (4 a b d e)

*/

/*
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)

3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (1 b) (2 b c) (4 a b d e)
(2 a c) (1 b) (2 b c) (4 a b d e)
(2 a c) (1 b) (2 b c) (4 a b d e)

3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 d c) (1 e) (2 a c) (4 a c d e)
(2 d c) (1 e) (2 a c) (4 a c d e)
(2 d c) (1 e) (2 a c) (4 a c d e)

*/

#include <bits/stdc++.h>

using namespace std;
char dna[55][1005];
int acgt(int k,int n)
{
    int a,c,g,t;
    a=c=g=t=0;
    for(int i=0;i<n;i++)
    {
        if(dna[i][k]=='A')a++;
        else if(dna[i][k]=='C')c++;
        else if(dna[i][k]=='G')g++;
        else if(dna[i][k]=='T')t++;
    }
    if(a>=c&&a>=g&&a>=t) {printf("A");return c+g+t;}
    if(c>=a&&c>=g&&c>=t) {printf("C");return a+g+t;}
    if(g>=c&&g>=a&&g>=t) {printf("G");return c+a+t;}
    if(t>=c&&t>=g&&t>=a) {printf("T");return c+g+a;}
}
int main()
{
    int k,n,m;
    cin>>k;
    while(k--)
    {
        int sum=0;
        scanf("%d%d",&n,&m);getchar();
        for(int i=0;i<n;i++) gets(dna[i]);
        for(int i=0;i<m;i++)
        {
            sum+=acgt(i,n);
        }
        cout<<endl<<sum<<endl;
    }
    return 0;
}

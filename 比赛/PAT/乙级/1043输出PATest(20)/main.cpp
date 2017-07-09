#include <bits/stdc++.h>

using namespace std;
int P,A,T,e,s,t;
int main()
{
    char ch;
    while(~scanf("%c",&ch))
    {
        if(ch=='P')P++;
        else if(ch=='A')A++;
        else if(ch=='T')T++;
        else if(ch=='e')e++;
        else if(ch=='s')s++;
        else if(ch=='t')t++;
    }
    while(P+A+T+e+s+t)
    {
        if(P){printf("P");P--;}
        if(A){printf("A");A--;}
        if(T){printf("T");T--;}
        if(e){printf("e");e--;}
        if(s){printf("s");s--;}
        if(t){printf("t");t--;}
    }
    cout<<endl;
    return 0;
}

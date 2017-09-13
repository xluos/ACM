#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char s[5];
    cin>>n;
    sprintf(s,"%03d",n);
    for(int i=0;i<s[0]-'0';i++) printf("B");
    for(int i=0;i<s[1]-'0';i++) printf("S");
    for(int i=0;i<s[2]-'0';i++) printf("%d",i+1);
    cout<<endl;
    return 0;
}

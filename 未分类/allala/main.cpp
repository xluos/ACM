#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
int a[55][10005];
int main()
{
    int n,k,m[55],t,x,y;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        cin>>m[j];
        for(int i=0;i<m[j];i++)
            cin>>a[j][i];
    }
    cin>>k;
    while(k--)
    {
        cin>>x>>y;
        set<int> s,ss,s1,s2;
        for(int i=0;i<m[x];i++)
            s1.insert(a[x][i]);
        for(int i=0;i<m[y];i++)
            s2.insert(a[y][i]);
        set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s,s.begin()));
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s,s.begin()));
        printf("%.2lf\n",ss.size()/s.size());
    }
    return 0;
}
/*#include <iostream>
#include<cstdlib>
using namespace std;
int yinshu(int x,int y)
{
    if(x<y)
    {
        int tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    if(x%y == 0)
        return abs(y);
    else
        return yinshu(y,x%y);
}
int main(void)
{
    int a,b,c,d;
    char optr,num;
    while(cin >> a >> num >> b >> optr >> c >> num >> d)
    {
        int x,y;
        switch(optr)
        {
        case '+':
        {
            x = a*d+b*c;
            y = b*d;
            break;
        }
        case '-':
        {
            x = a*d-b*c;
            y = b*d;
            break;
        }
        }
        if(x == 0)
            cout << 0 << endl;
        else if(y/yinshu(x,y) == 1)
            cout << x/yinshu(x,y) << endl;
        else
            cout << x/yinshu(x,y) << "/" << y/yinshu(x,y) << endl;
    }
    return 0;
}
*/

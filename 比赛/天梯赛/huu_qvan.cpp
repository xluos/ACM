/*#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;
int main()
{
    int m,n,m1,n1;
    cin>>m>>n;
    m1=m;n1=n;
    int t;int a[105],aa[105],b[105],bb[105];
    cin>>t;
    for(int i=0;i<t;i++)
        cin>>a[i]>>aa[i]>>b[i]>>bb[i];
    for(int i=0;i<t;i++)
    {
        if(aa[i]==a[i]+b[i]&&bb[i]==a[i]+b[i])
            continue;
        else if(aa[i]!=a[i]+b[i]&&bb[i]!=a[i]+b[i])
            continue;
        else if(aa[i]==a[i]+b[i])
            m--;
        else if(bb[i]==a[i]+b[i])
            n--;
        if(m<0&&n>=0)
        {
            cout<<"A"<<endl;
            cout<<n1-n<<endl;
            break;
        }
        else if(n<0&&m>=0)
        {
            cout<<"B"<<endl;
            cout<<m1-m<<endl;
            break;
        }

           // continue;
    }
    return 0;
}
*/


#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int j,y,n,jhan,jhua,yhan,yhua,a,b;
	cin>>j>>y;
	a=j;b=y;
	cin>>n;
	while(n--)
	{
		cin>>jhan>>jhua>>yhan>>yhua;
		int sum=jhan+yhan;
		if((jhua==sum)&&(yhua==sum))
			continue;
		if(jhua==sum)
			j--;
		if(yhua==sum)
			y--;
		if(j==0)
		{
			printf("A\n%d\n",b-y);
			break;
		}
		if(y==0)
		{
			printf("B\n%d\n",a-j);
			break;
		}
	}

	return 0;

}



#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int w;
    string s[]={"Yes","Yes","No"};
    scanf("%d",&w);
    while(w--)
    {
    	int a,b;
    	scanf("%d %d",&a,&b);
    	cout<<s[2-w]<<endl;
    }
}

/*#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct zhanghu{
	char name[20];
	char pass[20];
};
bool mi(char *s)
{
	int k=0;
	for(;*s!=0;s++)
	{
		if(*s=='1')
		{
			*s='@';
			k=1;
		}
		if(*s=='0')
		{
			*s='%';
			k=1;
		}
		if(*s=='l')
		{
			*s='L';
			k=1;
		}
		if(*s=='O')
		{
			*s='o';
			k=1;
		}
	}
	return k;
}
int main()
{
	zhanghu z[1003];
	int w;cin>>w;
	int num=0,vis[1005];
	for(int i=0;i<w;i++)
	{
		scanf("%s %s",z[i].name,z[i].pass);
		if(mi(z[i].pass))
			vis[num++]=i;
	}
	if(num==0)
	cout<<"There are "<<w<<" accounts and no account is modified"<<endl;
	else if(num==1)
	cout<<"There is 1 account and no account is modified"<<endl;
	else
	{
	cout<<num<<endl;
	for(int i=0;i<num;i++)
	{
		printf("%s %s\n",z[vis[i]].name,z[vis[i]].pass);
	}
	}
    return 0;
}
*/


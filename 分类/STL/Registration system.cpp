#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int w;cin>>w;
	map<string,int>mp;
	string s;
	char str[10];
	while(w--)
	{
		cin>>s;
		if(!mp[s])
		{
			cout<<"OK"<<endl;
			
		}
		else
		{
			/*string ans=s;
			for(int i=1;;i++)
			{
				sprintf(str,"%d",i);
				ans=s+str;
				if(!mp[ans])
				{
					cout<<ans<<endl;
					mp[ans]=1;
					break;
				}
			}*/
			cout<<s<<mp[s]<<endl;
		}mp[s]++;
	}
    return 0;
}



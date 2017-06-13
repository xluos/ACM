#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[25];
int atoi(string a)
{

}
int main()
{
    queue<int>q;

    int w;cin>>w;
    while(w--)
    {
        int m;cin>>m;getchar();
        double sum=0,t=1;
        while(m--)
        {
           gets(s);
           if(s[0]=='I')
                q.push(-1);
           if(s[0]=='S')
           {
               int sum=0;
               for(int i=5;s[i];i++)
               {
                   sum=sum*10+s[i]-'0';
               }
               q.push(sum);
           }
           if(s[0]=='O')
                q.push(-2);
        }
        while(!q.empty())
        {
            int x;
            x=q.front();
            q.pop();
            if(x==-1)t*=20;
            else if(x==-2)t/=20;
            else
            {
                sum+=x/t;
            }
        }
        printf("%.0lf\n",sum*60);

    }
    return 0;
}
/*×îÓÅ³ÌÐò

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m;
	string s;
	cin>>m;
	while(m--)
	{
		int p=1,n,t=0,tt;
		cin>>n;
		while(n--)
		{
			cin>>s;
			if(s=="STAY")
			{
				cin>>tt;
				t+=tt*60/p;
			}
			else if(s=="IN") p*=20;
			else p/=20;
		}
		cout<<t<<endl;
	}
}
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int hui(char s[])
{
	int l=strlen(s);
	if(l%2)
        return 0;
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1])
		return 0;
	}
	return 1;
}
int main()
{
    int w;cin>>w;
    getchar();
    while(w--)
    {
        char s[105],a[50];
        gets(s);
        int l=strlen(s),k=l;
        if(l%2)
        {
            cout<<l<<endl;
            continue;
        }
        while(1)
        {
            if(hui(s))
			{
				l/=2;
				s[l]=0;
				k /= 2;
			}
			else
				break;
        }
		cout<<k<<endl;
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char s[1000];
	int w;cin>>w;
	while(w--)
	{
		scanf("%s",s);
		for(int i=0;s[i];i++)
		{
			if(s[i]>='a'&&s[i]<='z')
				s[i] -= 32;
			else if(s[i]>='A'&&s[i]<='Z')
				s[i] += 32;
		}
		printf("%s\n",s);
	}
    return 0;
}



#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int w;cin>>w;
	getchar();
	while(w--)
	{
		int sum=0;
		while(1)
		{
			char ch;
			scanf("%c",&ch);
			if(ch=='\n')break;
			if(ch>='a'&&ch<='z')sum++;
		}
		sum %= 26;
		if(!sum)sum+=26;
		printf("%c\n",'a'+sum-1);
	}
    return 0;
}



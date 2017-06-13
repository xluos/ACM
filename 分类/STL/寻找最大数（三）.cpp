/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s[20];
    int sl,i,max_location,max_l;
    int k,l;
    while(~scanf("%s%d",s,&k))
    {
        i=0;
        l=strlen(s);
        while(k&&i!=l)
        {
            if(k>(l-i)) max_l=l-i;
            else max_l=k;
            max_location=i;
            for(int j=i+1; j<=i+max_l; j++)
            {
                if(s[j]>s[max_location]) max_location=j;
            }
            if(max_location!=i)
            {
                char t;
                t=s[max_location];
                for(int j=max_location; j>i; j--)
                {
                    s[j]=s[j-1];
                }
                s[i]=t;
                k-=(max_location-i);
            }
            i++;
        }
        printf("%s\n",s);
    }
    return 0;
}*/

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void myswap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
    *b=t;
}
int main()
{
	char s[20];
	int k;
	while(~scanf("%s %d",s,&k))
	{
		int i=0,l=strlen(s);
		for(int t=1;k>0;t++)
		{
			char max=0,nmax=0;
			int km=0;
			for(i=t;i<k+t&&i<l;i++)
			{
				if(s[i]>max)
				{
					max=s[i];
					km=i;
				}
			}
			if(max==nmax)break;
			for(int j=km;j>0;j--)
			{
				if(s[j]>s[j-1]&&k>0)
				{
					myswap(&s[j],&s[j-1]);
					k--;
				}
			}

		}
		printf("%s\n",s);
	}
    return 0;
}


/*#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void myswap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
    *b=t;
}
int main()
{
	char s[20];
	int k;
	while(~scanf("%s %d",s,&k))
	{
		int i=0,l=strlen(s);
		for(int t=1;k+t<l;t++)
		{
			char max=0,nmax=0;
			int km=0;
			for(i=t;i<k+t&&i<l;i++)
			{
				if(s[i]>max)
				{
					max=s[i];
					km=i;
				}
			}
			//if(max==nmax)break;
			for(int j=km;j>0;j--)
			{
				if(s[j]>s[j-1]&&k>0)
				{
					myswap(&s[j],&s[j-1]);
					k--;
				}
			}

		}
		printf("%s\n",s);
	}
    return 0;
}*/
/*
92932344922189532 39
99998533242422132
99998542323422132
868026756694756761 7
887626056694756761
887660256694756761
*/

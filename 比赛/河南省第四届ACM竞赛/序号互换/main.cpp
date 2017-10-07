#include <bits/stdc++.h>

using namespace std;
char ch[]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main()
{
    char s[100];
    int w;cin>>w;
    getchar();
    while(w--)
    {
        scanf("%s",s);
        if(s[0]<='9'&&s[0]>='0')
        {
            int i=0;
            int ans[20];
            sscanf(s,"%d",&ans[0]);


            for(i=0;ans[i]>26;i++)
            {
                if(ans[i]>26)
                {

                    ans[i+1]=ans[i]/26;
                    ans[i]=ans[i]%26;
                    if(ans[i]==0)ans[i+1]--;
                }
            }
            for(;i>=0;i--)
            {
                printf("%c",ch[ans[i]]);
            }
            printf("\n");
        }
        else
        {
            int l=strlen(s),a=0;
            for(int i=0;i<l;i++)
            {
                a=a*26+s[i]-'A'+1;
            }
            printf("%d\n",a);
        }
    }
    return 0;
}

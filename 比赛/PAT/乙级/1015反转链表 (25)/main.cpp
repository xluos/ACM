#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data,next;
}mp[100005];
int main()
{
    int head,n,k,ans,flag=1,myhead;
    cin>>head>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>ans;
        cin>>mp[ans].data>>mp[ans].next;
    }
    while(n>k)
    {
        int ans_head,new_head,new_next,ans_next,shang;
        for(int i=0;i<k;i++)
        {
            if(i==0)
            {
                new_next=mp[head].next;
                new_head=head;
                shang=head;
                ans_head=new_next;
            }
            else if(i==k-1)
            {
                mp[new_head].next=mp[ans_head].next;
                mp[ans_head].next=shang;
                head=mp[new_head].next;
                if(flag)
                {
                    myhead=ans_head;
                    flag=0;
                }
                n-=k;
            }
            else
            {
                ans_next = mp[ans_head].next;
                mp[ans_head].next=shang;
                shang=ans_head;
                ans_head=ans_next;
            }

        }

    }
    head=myhead;
    while(1)
    {
        printf("%05d %d ",head,mp[head].data);
        if(mp[head].next==-1)
        {
            printf("%d\n",mp[head].next);
            break;
        }
        else
        {
            printf("%05d\n",mp[head].next);
            head=mp[head].next;
        }

    }
    return 0;
}

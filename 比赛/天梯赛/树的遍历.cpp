#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct node{
	int data;
	node *l;
	node *r;
};
node *chuang2chashu(int *z,int *h,int n)
{
	node *b;
	int r,i,k;
	if(n<=0)return NULL;
	r=*(h+n-1);
	b=(node *)malloc(sizeof(node));
	b->data=r;
	for(i=0;i<n;i++)
		if(*(z+i)==r)break;
	b->l=chuang2chashu(z,h,i);
	b->r=chuang2chashu(z+i+1,h+i,n-i-1);
	return b;
}
int main()
{
	int w,h[35],z[35],k=1;
	node *head,*qq;
	queue<node*>q;
	cin>>w;
	for(int i=0;i<w;i++)
		cin>>h[i];
	for(int i=0;i<w;i++)
		cin>>z[i];
	head=chuang2chashu(z,h,w);
	
	q.push(head);
	while(!q.empty())
	{
		qq=q.front();
		q.pop();
		if(k){cout<<qq->data;k=0;}
		else{
			cout<<" "<<qq->data;
		}
		if(qq->l!=NULL)
		q.push(qq->l);
		if(qq->r!=NULL)
		q.push(qq->r);
	}
	cout<<endl;
    return 0;
}



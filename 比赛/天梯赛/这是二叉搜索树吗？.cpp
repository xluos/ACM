#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct node{
	int data;
	node *l,*r;
};
bool cmp(int a,int b)
{
	return a>b;
}
node *chuang2chashu(int *z,int *x,int n)
{
	node *head;
	if(n<=0)return NULL;
	int r=*x,i;
	head=(node*)malloc(sizeof(node));
	head->data=r;
	for(i=0;i<n;i++)
		if(*(z+i)==r)break;
	head->l=chuang2chashu(z,x+1,i);
	head->r=chuang2chashu(z+i+1,x+i+1,n-i-1);
	return head;
}
int sousuo2cs(node *head)
{
	int l,r;
	if(head->l!=NULL&&((head->l)->data<head->data))
		l=sousuo2cs(head->l);
	else
		return 0;
	if(head->r!=NULL&&((head->r)->data>head->data))
		r=sousuo2cs(head->r);
	else
		return 0;
	if(l&&r)return 1;
}
int jsousuo2cs(node *head)
{
	int l,r;
	if(head->l!=NULL&&((head->l)->data>head->data))
		l=jsousuo2cs(head->l);
	else
		return 0;
	if(head->r!=NULL&&((head->r)->data<head->data))
		r=jsousuo2cs(head->r);
	else
		return 0;
	if(l&&r)return 1;
}
int main()
{
	node *head,*jhead;
	int w,z[1005],x[1005];
	cin>>w;
	for(int i=0;i<w;i++)
	{
		cin>>x[i];
		z[i]=x[i];
	}
	sort(z,z+w);
	head=chuang2chashu(z,x,w);
	sort(z,z+w,cmp);
	jhead=chuang2chashu(z,x,w);
	if(sousuo2cs(head)||jsousuo2cs(jhead))
	{
		cout<<"YES"<<endl;
		//put_shu_hou(head);
	}
	else
		cout<<"NO"<<endl;
	return 0;
}

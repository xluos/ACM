//#include<bist/stdc++.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	FILE *fp=fopen("in.txt","w");
	fprintf(fp,"100\n");
	for(int j=0;j<10000000;j++)
	{
		fprintf(fp,"%d \n",j);
	}
	fclose(fp);
}

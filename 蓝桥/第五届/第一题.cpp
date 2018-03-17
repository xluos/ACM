#include<stdio.h> 

int get_word_num(char* buf)
{
	int n = 0;   
	int tag = 1; 
	char* p = buf;
	
	for(;*p!=0 && *p!=13 && *p!=10;p++){
		if(*p==' ' && tag==0) tag=1;
		if(*p!=' ' && tag==1) { n++; tag=0; }   //МоїХ
	}
	
	return n;
}

int main()
{
	char buf[1000];
	fgets(buf,1000,stdin);
	
	printf("%d\n", get_word_num(buf));
	return 0;
}


#include<stdio.h>
int getnum(int a,int b,int c,int d,int e)
{
	return a*10000+b*1000+c*100+d*10+e;
}
int main()
{
	int xiang,rui,sheng,hui,san,yang,xian,qi;
	int vis[10] = {0};
	for(int xiang=1;xiang<=9;xiang++)
	{
		if(!vis[xiang]) {vis[xiang] = 1;
		for(int san=1;san<=9;san++)
		{
			if(!vis[san]) {vis[san] = 1;
			for(int rui=0;rui<=9;rui++)
			{
				if(!vis[rui]) {vis[rui] = 1;
				for(int yang=0;yang<=9;yang++)
				{
					if(!vis[yang]) {vis[yang] = 1;S
					for(int sheng=0;sheng<=9;sheng++)
					{
						if(!vis[sheng]) {vis[sheng] = 1;
						for(int xian=0;xian<=9;xian++)
						{
							if(!vis[xian]) {vis[xian] = 1;
							for(int hui=0;hui<=9;hui++)
							{
								if(!vis[hui]) {vis[hui] = 1;
								for(int qi=0;qi<=9;qi++)
								{
									if(!vis[qi]) {vis[qi] = 1;
									if(getnum(0,xiang,rui,sheng,hui) + getnum(0,san,yang,xian,rui) == getnum(san,yang,sheng,rui,qi))
									{
										//printf("rui == %d\n",rui);
										//printf("san==%d yang==%d xian==%d rui==%d   sum == %d\n",san,yang,xian,rui,getnum(0,san,yang,xian,rui));
										printf("%d + %d == %d\n",getnum(0,xiang,rui,sheng,hui),getnum(0,san,yang,xian,rui),getnum(san,yang,sheng,rui,qi));
									}
									vis[qi] = 0;}	
								}
								vis[hui] = 0;}		
							}
							vis[xian] = 0;}	
						}
						vis[sheng] = 0;}		
					}
					vis[yang] = 0;}		
				}
				vis[rui] = 0;}		
			}
			vis[qi] = 0;}	
		}
		vis[xiang] =0;}
	}
	return 0;
} 

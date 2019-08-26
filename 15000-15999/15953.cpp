#include <stdio.h>
int T;
int make_sum(int a, int b)
{
	int r1=0;
	int r2=0;
	if(a<=1)
	{
		r1=5000000;
	}
	else if(a<=3)
		r1=3000000;
	else if(a<=6)
	{
		r1=2000000;
	}
	else if(a<=10)
		r1=500000;
	else if(a<=15)
		r1=300000;
	else if(a<=21)
		r1=100000;
	else if(a<=100)
		r1=0;
	else if(a==0)
		r1=0;


	if(b<=1)
		r2=5120000;
	else if(b<=3)
		r2=2560000;
	else if(b<=7)
		r2=1280000;
	else if(b<=15)
		r2=640000;
	else if(b<=31)
		r2=320000;
	else if(b<=64)
		r2=0;
	else if(b==0)
		r2=0;
	return r1+r2;	
}
int main(void)
{
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int result=make_sum(a,b);
		printf("%d\n",result);
	}
}	

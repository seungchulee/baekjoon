#include <stdio.h>
int main(void)
{
	int num;
	int result=0;
	scanf("%d",&num);
	
	while(num>0)
	{
		if(num%5==0)
		{
			num-=5;
			result++;
		}
		else if(num%3==0)
		{
			num-=3;
			result++;
		}
		else if(num>5)
		{
			num-=5;
			result++;
		}
		else
		{
			result=-1;
			break;
		}
	}
	printf("%d",result);

}


#include <stdio.h>
int main(void)
{
	int sum=0;
	int min=1000;

	for(int i=0;i<7;i++)
	{
		int num;
		scanf("%d",&num);
		if(num%2==1)
		{
			sum+=num;
			if(num<min)
				min=num;
		}
	}
	if(sum==0)
		printf("-1");
	else
	{
		printf("%d\n%d",sum,min);
	}
}

#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++)
	{
		int len=i;
		int sum=0;
		while(1)
		{
			if(len/10==0)
			{
				sum+=len;
				break;
			}
			sum+=len%10;
			len/=10;
		}
		if(sum+i==N)
		{
			printf("%d",i);
			break;
		}
	}
	if(i>=N)
		printf("0");
	
}

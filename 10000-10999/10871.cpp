#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N,X;
	int *num;
	scanf("%d %d",&N,&X);
	num=(int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num[i]);
	}
	for(int i=0;i<N;i++)
	{
		if(num[i]<X)
		{
			printf("%d ",num[i]);
		}
	}
}

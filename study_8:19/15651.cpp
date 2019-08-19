#include <stdio.h>

int N,M;
int arr[10];
void func(int index)
{
	if(index==M)
	{
		for(int j=0;j<M;j++)
			printf("%d ",arr[j]);
		printf("\n");
		return;
	}

	for(int i=1;i<=N;i++)
	{
		arr[index]=i;
		func(index+1);
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	func(0);
}


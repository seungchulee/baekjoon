#include <stdio.h>
int arr[10];
int N,M;
void func(int index, int start)
{
	if(index==M)
	{
		for(int j=0;j<M;j++)
			printf("%d ",arr[j]);
		printf("\n");
		return;
	}
	for(int i=start;i<=N;i++)
	{
		arr[index]=i;
		func(index+1, i+1);
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	func(0,1);
	return 0;
}

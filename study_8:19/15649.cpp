#include <stdio.h>
int N,M;
int arr[10];
int c[10]={false};
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
		if(c[i]==true)
			continue;
		arr[index]=i;
		c[i]=true;
		func(index+1);
		c[i]=false;
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	func(0);
}

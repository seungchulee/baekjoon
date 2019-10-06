#include <stdio.h>
#include <cstring>
int N;
int arr[10];
int check[10];
void func(int index)
{
	if(index==N)
	{
		for(int i=0;i<N;i++)
			printf("%d ",check[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(check[i]>=0)
			continue;
		check[i]=i;
		func(index+1);
		check[i]=-1;

	}
}

int main(void)
{
	memset(check,-1,sizeof(check));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}

	func(0);
}

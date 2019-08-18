#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d",&N);
	long int arr[91];

	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<=N;i++)
		arr[i]=arr[i-1]+arr[i-2];
	printf("%ld",arr[N]);
}

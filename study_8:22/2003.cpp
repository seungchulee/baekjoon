#include <stdio.h>
int N,M;
int arr[10000];
int main(void)
{
	scanf("%d %d",&N,&M);
	int sum=0;
	int left=0,right=0;

	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	int result=0;
	while(1)
	{
		if(sum>=M)
			sum-=arr[left++];
		else if(right==N)
			break;
		else
			sum+=arr[right++];
		if(sum==M)
			result++;

	}
	printf("%d",result);
}

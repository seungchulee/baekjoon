#include <stdio.h>
int main(void)
{
	int N,M;
	int arr[100001];
	int dp[100001];
	
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	dp[0]=arr[0];
	for(int i=1;i<N;i++)
		dp[i]=dp[i-1]+arr[i];
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[b-1]-dp[a-2]);
	}
}

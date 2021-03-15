#include <stdio.h>
#include <cstring>
int main(void)
{
	int arr[301][301];
	int dp[301][301];
	memset(dp,0,sizeof(dp));
	memset(arr,0,sizeof(arr));
	int N,M;
	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
		}
	}

	int K;
	scanf("%d",&K);
	for(int t=0;t<K;t++)
	{
		int i,j,x,y;
		scanf("%d %d %d %d",&i,&j,&x,&y);
		printf("%d\n",dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1]);
	}

}

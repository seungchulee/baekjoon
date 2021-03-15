#include <stdio.h>
#include <cstring>
int dx[2]={1,0};
int dy[2]={0,1};
int main(void)
{
	int arr[1001][1001];
	int H,W,N;
	scanf("%d %d %d",&H,&W,&N);
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int dp[1001][1001];
	memset(dp,0,sizeof(dp));
	dp[0][0]=N;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			if(arr[i][j]==1)
			{
				dp[i+1][j]+=dp[i][j]/2;
				dp[i][j+1]+=(dp[i][j]%2==0) ? dp[i][j]/2 : dp[i][j]/2+1;
			}
			else
			{
				dp[i+1][j]+=(dp[i][j]%2==0) ? dp[i][j]/2 : dp[i][j]/2+1;
				dp[i][j+1]+=dp[i][j]/2;
			}
		}
	}
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			dp[i][j]%=2;	
		}

	}
	int i=0,j=0;
	while(i>=0  && j>=0 && i<H && j<W)
	{
		if(arr[i][j]==1)
		{
			if(dp[i][j]==1)
			{
				j++;
			}
			else
				i++;
		}
		else
		{
			if(dp[i][j]==1)
				i++;
			else
				j++;
		}
	}
	printf("%d %d",i+1,j+1);

}

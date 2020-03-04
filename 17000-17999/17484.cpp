#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[7][7];
int dp[4][7][7];
int n,m;
bool isValid(int y)
{
	if(y<0 || y>=m)
		return false;
	else
		return true;

}
int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	}
	for(int i=0;i<m;i++)
	{
		dp[0][0][i]=arr[0][i];
		dp[1][0][i]=arr[0][i];
		dp[2][0][i]=arr[0][i];
	}
	for(int i=0;i<n;i++)
	{
		dp[0][i][0]=10000000;
		dp[2][i][m-1]=10000000;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(isValid(j-1) && isValid(j+1))
			{
				dp[0][i][j]=min(dp[1][i-1][j-1],dp[2][i-1][j-1]) + arr[i][j];
				dp[1][i][j]=min(dp[0][i-1][j],dp[2][i-1][j])+arr[i][j];
				dp[2][i][j]=min(dp[0][i-1][j+1],dp[1][i-1][j+1])+arr[i][j];
			}
			else if(!isValid(j-1) && isValid(j+1))
			{
				dp[1][i][j]=min(dp[0][i-1][j],dp[2][i-1][j])+arr[i][j];
				dp[2][i][j]=min(dp[1][i-1][j+1],dp[0][i-1][j+1])+arr[i][j];
			}
			else if(isValid(j-1) && !isValid(j+1))
			{
				dp[0][i][j]=min(dp[1][i-1][j-1],dp[2][i-1][j-1])+arr[i][j];
				dp[1][i][j]=min(dp[0][i-1][j],dp[2][i-1][j])+arr[i][j];
			}
					
		}
	}
	int mins=10000000;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<3;j++)
		{
			mins=min(mins,dp[j][n-1][i]);	
		}
	}
	printf("%d",mins);
}

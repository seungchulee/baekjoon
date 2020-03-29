#include <iostream>
using namespace std;
int arr[11][101010];
int dp[11][101010];
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	for(int i=0;i<m;i++)
		dp[i][0]=arr[i][0];
	for(int j=1;j<n;j++)
	{
		for(int i=0;i<m;i++)
		{
			int maxs=-1;
			int maxk;
			for(int k=0;k<m;k++)
			{
				if(k==i)
				{
					maxs=max(maxs,dp[k][j-1]+arr[i][j]/2);
				}
				else
				{
					maxs=max(maxs,dp[k][j-1]+arr[i][j]);
				}
			}
			dp[i][j]=maxs;
		}
	}
	int res=-1;
	for(int i=0;i<m;i++)
		res=max(res,dp[i][n-1]);
	cout << res;
}

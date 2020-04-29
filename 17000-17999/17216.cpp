#include <iostream>
using namespace std;
int arr[1010];
int dp[1010];
int main(void)
{
	int n;
	cin >> n;
	int maxs=-1;
	for(int i=1;i<=n;i++)
		cin >> arr[i];

	for(int i=1;i<=n;i++)
	{
		int minD = 0;
		for(int j=0;j<i;j++)
		{
			if(arr[i]<arr[j])
				if(minD < dp[j])
					minD = dp[j];
		}
		dp[i]=minD+arr[i];
		if(maxs<dp[i])
			maxs=dp[i];
	}
	cout << maxs;
}

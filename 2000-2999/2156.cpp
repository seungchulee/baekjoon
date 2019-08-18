#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[100001];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int *dp=(int*)malloc(sizeof(int)*(n+1));
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	dp[3]=max(max(arr[1]+arr[2],arr[2]+arr[3]),arr[1]+arr[3]);
	for(int i=4;i<=n;i++)
	{
		dp[i]=max(max(arr[i]+arr[i-1]+dp[i-3],arr[i]+dp[i-2]),dp[i-1]);
	}
	printf("%d",dp[n]);
}

#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	int *arr=(int*)malloc(sizeof(int)*(n+1));
	int *dp=(int*)malloc(sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	dp[1]=arr[1];
	int tmp=-10000;
	tmp=max(dp[1],tmp);
	for(int i=2;i<=n;i++)
	{
		
		dp[i]=max(arr[i],dp[i-1]+arr[i]);
		tmp=max(dp[i],tmp);
	}
	printf("%d",tmp);


	free(arr);
	free(dp);
}

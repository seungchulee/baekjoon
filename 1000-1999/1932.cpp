#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;


int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[501][501]={0};
	
	int cnt=1;
	int maxs=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			scanf("%d",&arr[i][j]);
			if(j==1)
			{
				arr[i][j]=arr[i][j]+arr[i-1][j];
			}
			else if(j==i)
			{
				arr[i][j]=arr[i][j]+arr[i-1][j-1];
			}
			else
			{
				arr[i][j]=arr[i][j]+max(arr[i-1][j-1],arr[i-1][j]);
			}
			if(maxs<arr[i][j])
				maxs=arr[i][j];
		}
	}
	printf("%d",maxs);

}

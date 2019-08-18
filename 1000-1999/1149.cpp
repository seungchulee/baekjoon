#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	scanf("%d",&N);
	int arr[1001][4];
	int res[1001];

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	res[1]=min(min(arr[1][1],arr[1][2]),arr[1][3]);
	for(int i=2;i<=N;i++)
	{
		arr[i][1]=arr[i][1]+min(arr[i-1][2],arr[i-1][3]);
		arr[i][2]=arr[i][2]+min(arr[i-1][1],arr[i-1][3]);
		arr[i][3]=arr[i][3]+min(arr[i-1][1],arr[i-1][2]);
	}
	int result=min(min(arr[N][1],arr[N][2]),arr[N][3]);
	printf("%d",result);
}

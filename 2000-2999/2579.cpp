#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int N;
	scanf("%d",&N);
	int *arr=(int*)malloc(sizeof(int)*(N+1));
	int *maxs=(int*)malloc(sizeof(int)*(N+1));
	for(int i=1;i<N+1;i++)
		scanf("%d",&arr[i]);
	maxs[1] = arr[1];
	maxs[2] = max(arr[1]+arr[2], arr[2]);
	maxs[3] = max(arr[1]+arr[3], arr[2]+arr[3]);
	for(int i=4;i<=N;i++)
	{
		maxs[i] = max(maxs[i-3]+arr[i]+arr[i-1],maxs[i-2]+arr[i]);
	}
	printf("%d",maxs[N]);
}

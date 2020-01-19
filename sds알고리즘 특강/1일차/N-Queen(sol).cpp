#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int arr[16][16];
int col[15];
int ans = 0;
bool promising(int cnt)
{
	for(int j=0;j<cnt;j++)
	{
		if(col[j]==col[cnt] || abs(col[j]-col[cnt])==(cnt-j))
			return false;
		
	}
	return true;
}
void DFS(int cnt)
{
	if (cnt == N)
	{
		ans++;
		return;
	}
	
	for(int j=0;j<N;j++)
	{
		col[cnt]=j;
		if(promising(cnt))
			DFS(cnt+1);
	}
}
int main(void)
{
	memset(arr, -1, sizeof(arr));
	scanf("%d", &N);
	DFS(0);
	printf("%d", ans);
}

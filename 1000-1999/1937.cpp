#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[501][501];
int visit[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int DFS(int x, int y)
{
	if(visit[x][y])
		return visit[x][y];

	visit[x][y]=1;

	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		
		if(ddx<0 || ddy<0 || ddx>=n || ddy>=n)
			continue;

		if(arr[ddx][ddy]>arr[x][y])
		{
			visit[x][y]=max(visit[x][y], DFS(ddx,ddy)+1);
		}
	}
	return visit[x][y];
}


int main(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	int maxs=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			int cnt=DFS(i,j);
			maxs=max(cnt,maxs);

		}
	}
	printf("%d",maxs);
}

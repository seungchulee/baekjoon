#include <stdio.h>
#include <cstring>
int arr[501][501];
int visit[501][501];
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dfs(int x, int y)
{
	if(x==n-1 && y==m-1)
		return 1;

	if(visit[x][y]==-1)
	{
		visit[x][y]=0;
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
				continue;

			if(arr[ddx][ddy]<arr[x][y])
			{
				visit[x][y]+=dfs(ddx,ddy);
			}
		}
	}
	return visit[x][y];
}
int main(void)
{
	memset(arr,0,sizeof(arr));
	memset(visit,-1,sizeof(visit));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	printf("%d",dfs(0,0));
}


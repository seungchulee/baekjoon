#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M,K;
int arr[101][101];
int visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int cnt=0;
void DFS(int x, int y)
{
	visit[x][y]=1;

	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(ddx<1 || ddy<1 || ddx>N || ddy>M)
			continue;
		if(arr[ddx][ddy]==1 && visit[ddx][ddy]==0)
		{
			cnt++;
			DFS(ddx,ddy);

		}
	}
}
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);

	memset(arr,0,sizeof(arr));
	memset(visit,0,sizeof(visit));
	for(int i=0;i<K;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1;

	}


	int maxs=-1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(arr[i][j]==1 && visit[i][j]==0)
			{
				cnt=1;
				DFS(i,j);
				if(maxs<cnt)
					maxs=max(maxs,cnt);
			}
		}
	}
	printf("%d",maxs);
	
}


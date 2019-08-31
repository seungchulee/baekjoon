#include <stdio.h>
#include <cstring>
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[101][101];
int visit[101][101];
int cnt_air;
void DFS(int x, int y)
{
	visit[x][y]=1;
	if(cnt_air>=2)
	{
		arr[x][y]=-1;
	}
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
			continue;
		if(arr[ddx][ddy]==0 && visit[ddx][ddy]==0)
			DFS(ddx,ddy);
	}
}
void DDFS(int x, int y)
{
	visit[x][y]=1;
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(arr[ddx][ddy]==0)
			cnt++;
	}
	if(cnt>=2)
		arr[x][y]=-2;

	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
			continue;
		if(arr[ddx][ddy]==1 && visit[ddx][ddy]==0)
			DDFS(ddx,ddy);
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int result=0;
	while(1)
	{
		memset(visit,0,sizeof(visit));

		cnt_air=0;

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(arr[i][j]==0 && visit[i][j]==0)
				{
					cnt_air++;
					DFS(i,j);
				}
			}

		}

		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(arr[i][j]==1 && visit[i][j]==0)
				{
					DDFS(i,j);	
					
				}
			}
		}
		int one_cnt=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{

				if(arr[i][j]==1)
					one_cnt++;
				if(arr[i][j]==-1 || arr[i][j]==-2)
					arr[i][j]=0;
				
			}

		}

		result++;
		if(one_cnt==0)
			break;

	}
	printf("%d",result);

}
